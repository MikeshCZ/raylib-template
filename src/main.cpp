#include "intro.hpp"
#include <raylib.h>
#include <string>

#define RAYGUI_IMPLEMENTATION
#include <raygui.h>

using namespace std;

int
main ()
{
  // === INITIALIZATION ===

  // --- Raylib Flags ---

  SetConfigFlags (FLAG_VSYNC_HINT);
  SetConfigFlags (FLAG_MSAA_4X_HINT);
  SetConfigFlags (FLAG_WINDOW_HIGHDPI);

  // --- Constants & Variables ---

  bool playIntro = true;                         // play raylib intro
  bool playMusic = true;                         // play background music
  bool IsStatsVisible = true;                    // show movement stats
  const Color COL_BACK = { 205, 245, 245, 255 }; // background color
  bool showMessageBox = false;                   // message box visible

  const string GAME_NAME = "Mikesh's Raylib template"; // game name
  const char *WINDOW_TITLE = GAME_NAME.c_str ();       // window title

  InitWindow (0, 0, WINDOW_TITLE); // Inicialization of main window

  const int CURRENT_MONITOR = GetCurrentMonitor (); // index of current monitor
  const int SCREEN_WIDTH = GetMonitorWidth (CURRENT_MONITOR);   // scr width
  const int SCREEN_HEIGHT = GetMonitorHeight (CURRENT_MONITOR); // scr height
  int fps = GetMonitorRefreshRate (CURRENT_MONITOR); // refresh rate FPS

  // --- Preparation before startup ---

  // Main window
  if (!IsWindowFullscreen ())
    ToggleFullscreen ();
  SetTargetFPS (fps);
  SetExitKey (KEY_F10);

  // Background music initialization
  InitAudioDevice ();
  Music music = LoadMusicStream ("assets/music.ogg");
  SetMusicVolume (music, 1.0f);
  if (playMusic)
    PlayMusicStream (music);

  // === INTRO ===

  if (playIntro)
    {
      Intro intro (WINDOW_TITLE); // Raylib Intro class
      SetTargetFPS (60);          // Set FPS to 60 to synchronize the music

      while (WindowShouldClose () == false && playIntro)
        {
          if (playMusic)
            {
              UpdateMusicStream (music);
            }

          if (!intro.IsIntroFininsh ())
            {
              BeginDrawing ();
              ClearBackground (RAYWHITE);
              intro.UpdateLogoScreen ();
              intro.DrawLogoScreen ();
              EndDrawing ();
            }
          else // End of intro
            {
              SetTargetFPS (fps); // reset FPS
              break;
            }
        }
    }

  // === MAIN LOOP ===

  while (WindowShouldClose () == false)
    {
      // --- Music ---

      if (playMusic)
        {
          UpdateMusicStream (music);
        }

      // --- 1. Event handling ---

      // Function keys
      if (IsKeyPressed (KEY_F5)) // toggle fullscreen
        {
          ToggleFullscreen ();
        }

      if (IsKeyPressed (KEY_F8)) // show stats
        {
          IsStatsVisible = !IsStatsVisible;
        }

      // --- 2. Update state ---

      // Update routines

      // --- 3. Drawing ---

      BeginDrawing ();        // start drawing
      ClearBackground (GRAY); // draw background

      // Raygui example
      if (GuiButton ((Rectangle){ 24, 24, 120, 30 }, "#191# Raygui Test"))
        showMessageBox = true;

      if (showMessageBox)
        {
          int result = GuiMessageBox (
              (Rectangle){ 85, 70, 250, 200 }, "#191# Message Box",
              "It works!!!\n\nTry:\n F5 to toggle fullscreen\nF8 to show "
              "stats\nF10 to quit",
              "Nice;Cool");

          if (result >= 0)
            showMessageBox = false;
        }

      if (IsStatsVisible)
        {
          DrawFPS (SCREEN_WIDTH - 90, 5); // display current FPS

          // Display stats
          DrawText (TextFormat ("Target FPS: %i", fps), 10, 10, 10, WHITE);
        }

      EndDrawing (); // end drawing
    }

  // === END PROCEDURE ===

  UnloadMusicStream (music);
  CloseAudioDevice ();
  CloseWindow ();
}