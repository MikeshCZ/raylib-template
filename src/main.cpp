#include "intro.hpp"
#include <algorithm>
#include <raylib.h>
#include <string>

#define RAYGUI_IMPLEMENTATION
#include <raygui.h>

// Detection of OS
#if defined(_WIN32) || defined(_WIN64)
#define OS_NAME "Windows"
#elif defined(__APPLE__) || defined(__MACH__)
#define OS_NAME "MacOS"
#elif defined(__linux__)
#define OS_NAME "Linux"
#elif defined(__unix__)
#define OS_NAME "Unix"
#elif defined(__ANDROID__)
#define OS_NAME "Android"
#elif defined(__FreeBSD__)
#define OS_NAME "FreeBSD"
#else
#define OS_NAME "NA"
#endif

using namespace std;

int
main ()
{
  // === INICIALIZACE ===

  // --- Raylib Flags ---

  SetConfigFlags (FLAG_VSYNC_HINT);
  SetConfigFlags (FLAG_MSAA_4X_HINT);
  SetConfigFlags (FLAG_WINDOW_HIGHDPI);

  // on macOS, we need to find out the resolution in full-screen mode in some
  // cases
  // if (std::string (OS_NAME) == "MacOS")
  //  SetConfigFlags (FLAG_FULLSCREEN_MODE);

  // --- Konstanty & Proměnné ---

  constexpr bool DEBUG = false; // DEBUG mód
  bool playIntro = !DEBUG;      // přehraj raylib intro
  bool playMusic = !DEBUG;      // hraj muziku na pozadí
  bool IsStatsVisible = DEBUG;  // zobrazit statistiky pohybu
  int windowRatio = 1;          // koeficient velikosti okna
  if (DEBUG)
    windowRatio = 2;              // v případě debugu poloviční okno
  InitWindow (1280, 720, "Init"); // otevřené okno pro získání info o rozlišení
  const int CURRENT_MONITOR = GetCurrentMonitor (); // index aktuální obrazovky
  const int SCREEN_WIDTH
      = GetMonitorWidth (CURRENT_MONITOR) / windowRatio; // šířka obrazovky
  const int SCREEN_HEIGHT
      = GetMonitorHeight (CURRENT_MONITOR) / windowRatio; // výška obrazovky
  int fps = GetMonitorRefreshRate (CURRENT_MONITOR);      // refresh rate FPS
  CloseWindow ();                                         // zavření init okna
  const string GAME_NAME = "Mikesh's Raylib template";    // název hry
  const char *WINDOW_TITLE = GAME_NAME.c_str ();          // nadpis okna
  const Color COL_BACK = { 205, 245, 245, 255 };          // barva pozadí
  bool showMessageBox = false; // message box visible
  // --- Příprava před spuštěním ---

  // Hlavní okno
  InitWindow (SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_TITLE);
  if (DEBUG xor !IsWindowFullscreen ())
    ToggleFullscreen ();
  SetTargetFPS (fps);
  // HideCursor ();
  SetExitKey (KEY_F10);

  // Inicializace hudby na pozadí
  InitAudioDevice ();
  Music music = LoadMusicStream ("assets/music.ogg");
  SetMusicVolume (music, 1.0f);
  if (playMusic)
    PlayMusicStream (music);

  // === INTRO ===

  Intro intro (WINDOW_TITLE); // Raylib Intro

  if (playIntro)
    {
      SetTargetFPS (60); // Nastavení FPS na 60, aby byla synchronizovaná hudba

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
          else // Konec intra
            {
              SetTargetFPS (fps); // nastavení FPS zpět
              break;
            }
        }
    }

  // === HLAVNÍ SMYČKA ===

  while (WindowShouldClose () == false)
    {
      // --- Hudba ---

      if (playMusic)
        {
          UpdateMusicStream (music);
        }

      // --- 1. Zpracování událostí ---

      // Funkční klávesy
      if (IsKeyPressed (KEY_F5)) // přepnout fullscreen
        {
          ToggleFullscreen ();
        }

      if (IsKeyPressed (KEY_F8)) // zobrazit statistiky
        {
          IsStatsVisible = !IsStatsVisible;
        }

      // --- 2. Aktualizace stavu ---

      // Update rutiny

      // --- 3. Vykreslení ---

      BeginDrawing ();        // začátek vykreslení
      ClearBackground (GRAY); // vykreslení pozadí

      if (GuiButton ((Rectangle){ 24, 24, 120, 30 }, "#191# Raygui Test"))
        showMessageBox = true;

      if (showMessageBox)
        {
          int result = GuiMessageBox (
              (Rectangle){ 85, 70, 250, 200 }, "#191# Message Box",
              "It works!!!\n\nTry:\n F5 to toogle fullscreen\nF8 to show "
              "stats\nF10 to quit",
              "Nice;Cool");

          if (result >= 0)
            showMessageBox = false;
        }

      if (IsStatsVisible)
        {
          DrawFPS (SCREEN_WIDTH - 90, 5); // vypíše aktuální FPS

          // Vypsání statistik
          DrawText (TextFormat ("Target FPS: %i", fps), 10, 10, 10, WHITE);
        }

      EndDrawing (); // konec vykreslení
    }

  // === UKONČOVACÍ PROCEDŮRA ===

  UnloadMusicStream (music);
  CloseAudioDevice ();
  // ShowCursor ();
  CloseWindow ();
}