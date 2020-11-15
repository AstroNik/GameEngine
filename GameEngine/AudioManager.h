#pragma once
#include <vector>
#include "SDL_mixer.h"  //required for audio
#include <iostream>
using namespace std;


class AudioManager
{
private:
	vector<Mix_Music*> m_vMusicTracks;
	vector<Mix_Chunk*> m_vSounds;

public:
	AudioManager();
	~AudioManager();
	bool Init();

	//Set volume of the music
	void SetMusicVolume(int volLevel);

	///loops=-1 means infinite
	void PlayMusic(int id, int loops = -1);


	void PlaySound(int id, int channel = -1, int loops = 0);


	void LoadMusic(const char* path);
	void LoadSound(const char* path);


	void UnloadMusic();
	void UnloadSound();

	void UnloadSingleMusic(int id);
	void UnloadSingleSound(int id);

	//Toggle music:: so that you can pause and resume the current music track
	void ToggleMusic();
};