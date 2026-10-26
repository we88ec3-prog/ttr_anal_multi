
undefined4 FUN_00812810(void)

{
  HMODULE hModule;
  FARPROC pFVar1;
  code *pcVar2;
  undefined4 *unaff_ESI;
  
  if (unaff_ESI == (undefined4 *)0x0) {
    return 0;
  }
  hModule = LoadLibraryA("openal32.dll");
  DAT_00fba90c = hModule;
  if (hModule != (HMODULE)0x0) {
    _memset(unaff_ESI,0,0x104);
    pFVar1 = GetProcAddress(hModule,"alEnable");
    *unaff_ESI = pFVar1;
    if (pFVar1 == (FARPROC)0x0) {
      FID_conflict__wprintf("Failed to retrieve \'%s\' function address\n",alEnable_exref);
      return 0;
    }
    pFVar1 = GetProcAddress(DAT_00fba90c,"alDisable");
    unaff_ESI[1] = pFVar1;
    pcVar2 = alDisable_exref;
    if (pFVar1 != (FARPROC)0x0) {
      pFVar1 = GetProcAddress(DAT_00fba90c,"alIsEnabled");
      unaff_ESI[2] = pFVar1;
      if (pFVar1 == (FARPROC)0x0) {
        FID_conflict__wprintf("Failed to retrieve \'%s\' function address\n",alIsEnabled_exref);
        return 0;
      }
      pFVar1 = GetProcAddress(DAT_00fba90c,"alGetBoolean");
      unaff_ESI[3] = pFVar1;
      if (pFVar1 == (FARPROC)0x0) {
        FID_conflict__wprintf("Failed to retrieve \'%s\' function address\n",alGetBoolean_exref);
        return 0;
      }
      pFVar1 = GetProcAddress(DAT_00fba90c,"alGetInteger");
      unaff_ESI[4] = pFVar1;
      pcVar2 = alGetInteger_exref;
      if (pFVar1 != (FARPROC)0x0) {
        pFVar1 = GetProcAddress(DAT_00fba90c,"alGetFloat");
        unaff_ESI[5] = pFVar1;
        if (pFVar1 == (FARPROC)0x0) {
          FID_conflict__wprintf("Failed to retrieve \'%s\' function address\n",alGetFloat_exref);
          return 0;
        }
        pFVar1 = GetProcAddress(DAT_00fba90c,"alGetDouble");
        unaff_ESI[6] = pFVar1;
        if (pFVar1 == (FARPROC)0x0) {
          FID_conflict__wprintf("Failed to retrieve \'%s\' function address\n",alGetDouble_exref);
          return 0;
        }
        pFVar1 = GetProcAddress(DAT_00fba90c,"alGetBooleanv");
        unaff_ESI[7] = pFVar1;
        pcVar2 = alGetBooleanv_exref;
        if (pFVar1 != (FARPROC)0x0) {
          pFVar1 = GetProcAddress(DAT_00fba90c,"alGetIntegerv");
          unaff_ESI[8] = pFVar1;
          if (pFVar1 == (FARPROC)0x0) {
            FID_conflict__wprintf
                      ("Failed to retrieve \'%s\' function address\n",alGetIntegerv_exref);
            return 0;
          }
          pFVar1 = GetProcAddress(DAT_00fba90c,"alGetFloatv");
          unaff_ESI[9] = pFVar1;
          if (pFVar1 == (FARPROC)0x0) {
            FID_conflict__wprintf("Failed to retrieve \'%s\' function address\n",alGetFloatv_exref);
            return 0;
          }
          pFVar1 = GetProcAddress(DAT_00fba90c,"alGetDoublev");
          unaff_ESI[10] = pFVar1;
          pcVar2 = alGetDoublev_exref;
          if (pFVar1 != (FARPROC)0x0) {
            pFVar1 = GetProcAddress(DAT_00fba90c,"alGetString");
            unaff_ESI[0xb] = pFVar1;
            if (pFVar1 == (FARPROC)0x0) {
              FID_conflict__wprintf
                        ("Failed to retrieve \'%s\' function address\n",alGetString_exref);
              return 0;
            }
            pFVar1 = GetProcAddress(DAT_00fba90c,"alGetError");
            unaff_ESI[0xc] = pFVar1;
            if (pFVar1 == (FARPROC)0x0) {
              FID_conflict__wprintf("Failed to retrieve \'%s\' function address\n",alGetError_exref)
              ;
              return 0;
            }
            pFVar1 = GetProcAddress(DAT_00fba90c,"alIsExtensionPresent");
            unaff_ESI[0xd] = pFVar1;
            pcVar2 = alIsExtensionPresent_exref;
            if (pFVar1 != (FARPROC)0x0) {
              pFVar1 = GetProcAddress(DAT_00fba90c,"alGetProcAddress");
              unaff_ESI[0xe] = pFVar1;
              if (pFVar1 == (FARPROC)0x0) {
                FID_conflict__wprintf
                          ("Failed to retrieve \'%s\' function address\n",alGetProcAddress_exref);
                return 0;
              }
              pFVar1 = GetProcAddress(DAT_00fba90c,"alGetEnumValue");
              unaff_ESI[0xf] = pFVar1;
              if (pFVar1 == (FARPROC)0x0) {
                FID_conflict__wprintf
                          ("Failed to retrieve \'%s\' function address\n",alGetEnumValue_exref);
                return 0;
              }
              pFVar1 = GetProcAddress(DAT_00fba90c,"alListeneri");
              unaff_ESI[0x10] = pFVar1;
              pcVar2 = alListeneri_exref;
              if (pFVar1 != (FARPROC)0x0) {
                pFVar1 = GetProcAddress(DAT_00fba90c,"alListenerf");
                unaff_ESI[0x11] = pFVar1;
                if (pFVar1 == (FARPROC)0x0) {
                  FID_conflict__wprintf
                            ("Failed to retrieve \'%s\' function address\n",alListenerf_exref);
                  return 0;
                }
                pFVar1 = GetProcAddress(DAT_00fba90c,"alListener3f");
                unaff_ESI[0x12] = pFVar1;
                if (pFVar1 == (FARPROC)0x0) {
                  FID_conflict__wprintf
                            ("Failed to retrieve \'%s\' function address\n",alListener3f_exref);
                  return 0;
                }
                pFVar1 = GetProcAddress(DAT_00fba90c,"alListenerfv");
                unaff_ESI[0x13] = pFVar1;
                pcVar2 = alListenerfv_exref;
                if (pFVar1 != (FARPROC)0x0) {
                  pFVar1 = GetProcAddress(DAT_00fba90c,"alGetListeneri");
                  unaff_ESI[0x14] = pFVar1;
                  if (pFVar1 == (FARPROC)0x0) {
                    FID_conflict__wprintf
                              ("Failed to retrieve \'%s\' function address\n",alGetListeneri_exref);
                    return 0;
                  }
                  pFVar1 = GetProcAddress(DAT_00fba90c,"alGetListenerf");
                  unaff_ESI[0x15] = pFVar1;
                  if (pFVar1 == (FARPROC)0x0) {
                    FID_conflict__wprintf
                              ("Failed to retrieve \'%s\' function address\n",alGetListenerf_exref);
                    return 0;
                  }
                  pFVar1 = GetProcAddress(DAT_00fba90c,"alGetListener3f");
                  unaff_ESI[0x16] = pFVar1;
                  pcVar2 = alGetListener3f_exref;
                  if (pFVar1 != (FARPROC)0x0) {
                    pFVar1 = GetProcAddress(DAT_00fba90c,"alGetListenerfv");
                    unaff_ESI[0x17] = pFVar1;
                    if (pFVar1 == (FARPROC)0x0) {
                      FID_conflict__wprintf
                                ("Failed to retrieve \'%s\' function address\n",
                                 alGetListenerfv_exref);
                      return 0;
                    }
                    pFVar1 = GetProcAddress(DAT_00fba90c,"alGenSources");
                    unaff_ESI[0x18] = pFVar1;
                    if (pFVar1 == (FARPROC)0x0) {
                      FID_conflict__wprintf
                                ("Failed to retrieve \'%s\' function address\n",alGenSources_exref);
                      return 0;
                    }
                    pFVar1 = GetProcAddress(DAT_00fba90c,"alDeleteSources");
                    unaff_ESI[0x19] = pFVar1;
                    pcVar2 = alDeleteSources_exref;
                    if (pFVar1 != (FARPROC)0x0) {
                      pFVar1 = GetProcAddress(DAT_00fba90c,"alIsSource");
                      unaff_ESI[0x1a] = pFVar1;
                      if (pFVar1 == (FARPROC)0x0) {
                        FID_conflict__wprintf
                                  ("Failed to retrieve \'%s\' function address\n",alIsSource_exref);
                        return 0;
                      }
                      pFVar1 = GetProcAddress(DAT_00fba90c,"alSourcei");
                      unaff_ESI[0x1b] = pFVar1;
                      if (pFVar1 == (FARPROC)0x0) {
                        FID_conflict__wprintf
                                  ("Failed to retrieve \'%s\' function address\n",alSourcei_exref);
                        return 0;
                      }
                      pFVar1 = GetProcAddress(DAT_00fba90c,"alSourcef");
                      unaff_ESI[0x1c] = pFVar1;
                      pcVar2 = alSourcef_exref;
                      if (pFVar1 != (FARPROC)0x0) {
                        pFVar1 = GetProcAddress(DAT_00fba90c,"alSource3f");
                        unaff_ESI[0x1d] = pFVar1;
                        if (pFVar1 == (FARPROC)0x0) {
                          FID_conflict__wprintf
                                    ("Failed to retrieve \'%s\' function address\n",alSource3f_exref
                                    );
                          return 0;
                        }
                        pFVar1 = GetProcAddress(DAT_00fba90c,"alSourcefv");
                        unaff_ESI[0x1e] = pFVar1;
                        if (pFVar1 == (FARPROC)0x0) {
                          FID_conflict__wprintf
                                    ("Failed to retrieve \'%s\' function address\n",alSourcefv_exref
                                    );
                          return 0;
                        }
                        pFVar1 = GetProcAddress(DAT_00fba90c,"alGetSourcei");
                        unaff_ESI[0x1f] = pFVar1;
                        pcVar2 = alGetSourcei_exref;
                        if (pFVar1 != (FARPROC)0x0) {
                          pFVar1 = GetProcAddress(DAT_00fba90c,"alGetSourcef");
                          unaff_ESI[0x20] = pFVar1;
                          if (pFVar1 == (FARPROC)0x0) {
                            FID_conflict__wprintf
                                      ("Failed to retrieve \'%s\' function address\n",
                                       alGetSourcef_exref);
                            return 0;
                          }
                          pFVar1 = GetProcAddress(DAT_00fba90c,"alGetSourcefv");
                          unaff_ESI[0x21] = pFVar1;
                          if (pFVar1 == (FARPROC)0x0) {
                            FID_conflict__wprintf
                                      ("Failed to retrieve \'%s\' function address\n",
                                       alGetSourcefv_exref);
                            return 0;
                          }
                          pFVar1 = GetProcAddress(DAT_00fba90c,"alSourcePlayv");
                          unaff_ESI[0x22] = pFVar1;
                          pcVar2 = alSourcePlayv_exref;
                          if (pFVar1 != (FARPROC)0x0) {
                            pFVar1 = GetProcAddress(DAT_00fba90c,"alSourceStopv");
                            unaff_ESI[0x23] = pFVar1;
                            if (pFVar1 == (FARPROC)0x0) {
                              FID_conflict__wprintf
                                        ("Failed to retrieve \'%s\' function address\n",
                                         alSourceStopv_exref);
                              return 0;
                            }
                            pFVar1 = GetProcAddress(DAT_00fba90c,"alSourcePlay");
                            unaff_ESI[0x24] = pFVar1;
                            if (pFVar1 == (FARPROC)0x0) {
                              FID_conflict__wprintf
                                        ("Failed to retrieve \'%s\' function address\n",
                                         alSourcePlay_exref);
                              return 0;
                            }
                            pFVar1 = GetProcAddress(DAT_00fba90c,"alSourcePause");
                            unaff_ESI[0x25] = pFVar1;
                            pcVar2 = alSourcePause_exref;
                            if (pFVar1 != (FARPROC)0x0) {
                              pFVar1 = GetProcAddress(DAT_00fba90c,"alSourceStop");
                              unaff_ESI[0x26] = pFVar1;
                              if (pFVar1 == (FARPROC)0x0) {
                                FID_conflict__wprintf
                                          ("Failed to retrieve \'%s\' function address\n",
                                           alSourceStop_exref);
                                return 0;
                              }
                              pFVar1 = GetProcAddress(DAT_00fba90c,"alGenBuffers");
                              unaff_ESI[0x27] = pFVar1;
                              if (pFVar1 == (FARPROC)0x0) {
                                FID_conflict__wprintf
                                          ("Failed to retrieve \'%s\' function address\n",
                                           alGenBuffers_exref);
                                return 0;
                              }
                              pFVar1 = GetProcAddress(DAT_00fba90c,"alDeleteBuffers");
                              unaff_ESI[0x28] = pFVar1;
                              pcVar2 = alDeleteBuffers_exref;
                              if (pFVar1 != (FARPROC)0x0) {
                                pFVar1 = GetProcAddress(DAT_00fba90c,"alIsBuffer");
                                unaff_ESI[0x29] = pFVar1;
                                if (pFVar1 == (FARPROC)0x0) {
                                  FID_conflict__wprintf
                                            ("Failed to retrieve \'%s\' function address\n",
                                             alIsBuffer_exref);
                                  return 0;
                                }
                                pFVar1 = GetProcAddress(DAT_00fba90c,"alBufferData");
                                unaff_ESI[0x2a] = pFVar1;
                                if (pFVar1 == (FARPROC)0x0) {
                                  FID_conflict__wprintf
                                            ("Failed to retrieve \'%s\' function address\n",
                                             alBufferData_exref);
                                  return 0;
                                }
                                pFVar1 = GetProcAddress(DAT_00fba90c,"alGetBufferi");
                                unaff_ESI[0x2b] = pFVar1;
                                pcVar2 = alGetBufferi_exref;
                                if (pFVar1 != (FARPROC)0x0) {
                                  pFVar1 = GetProcAddress(DAT_00fba90c,"alGetBufferf");
                                  unaff_ESI[0x2c] = pFVar1;
                                  if (pFVar1 == (FARPROC)0x0) {
                                    FID_conflict__wprintf
                                              ("Failed to retrieve \'%s\' function address\n",
                                               alGetBufferf_exref);
                                    return 0;
                                  }
                                  pFVar1 = GetProcAddress(DAT_00fba90c,"alSourceQueueBuffers");
                                  unaff_ESI[0x2d] = pFVar1;
                                  if (pFVar1 == (FARPROC)0x0) {
                                    FID_conflict__wprintf
                                              ("Failed to retrieve \'%s\' function address\n",
                                               alSourceQueueBuffers_exref);
                                    return 0;
                                  }
                                  pFVar1 = GetProcAddress(DAT_00fba90c,"alSourceUnqueueBuffers");
                                  unaff_ESI[0x2e] = pFVar1;
                                  pcVar2 = alSourceUnqueueBuffers_exref;
                                  if (pFVar1 != (FARPROC)0x0) {
                                    pFVar1 = GetProcAddress(DAT_00fba90c,"alDistanceModel");
                                    unaff_ESI[0x2f] = pFVar1;
                                    if (pFVar1 == (FARPROC)0x0) {
                                      FID_conflict__wprintf
                                                ("Failed to retrieve \'%s\' function address\n",
                                                 alDistanceModel_exref);
                                      return 0;
                                    }
                                    pFVar1 = GetProcAddress(DAT_00fba90c,"alDopplerFactor");
                                    unaff_ESI[0x30] = pFVar1;
                                    if (pFVar1 == (FARPROC)0x0) {
                                      FID_conflict__wprintf
                                                ("Failed to retrieve \'%s\' function address\n",
                                                 alDopplerFactor_exref);
                                      return 0;
                                    }
                                    pFVar1 = GetProcAddress(DAT_00fba90c,"alDopplerVelocity");
                                    unaff_ESI[0x31] = pFVar1;
                                    pcVar2 = alDopplerVelocity_exref;
                                    if (pFVar1 != (FARPROC)0x0) {
                                      pFVar1 = GetProcAddress(DAT_00fba90c,"alcGetString");
                                      unaff_ESI[0x32] = pFVar1;
                                      if (pFVar1 == (FARPROC)0x0) {
                                        FID_conflict__wprintf
                                                  ("Failed to retrieve \'%s\' function address\n",
                                                   alcGetString_exref);
                                        return 0;
                                      }
                                      pFVar1 = GetProcAddress(DAT_00fba90c,"alcGetIntegerv");
                                      unaff_ESI[0x33] = pFVar1;
                                      if (pFVar1 == (FARPROC)0x0) {
                                        FID_conflict__wprintf
                                                  ("Failed to retrieve \'%s\' function address\n",
                                                   alcGetIntegerv_exref);
                                        return 0;
                                      }
                                      pFVar1 = GetProcAddress(DAT_00fba90c,"alcOpenDevice");
                                      unaff_ESI[0x34] = pFVar1;
                                      pcVar2 = alcOpenDevice_exref;
                                      if (pFVar1 != (FARPROC)0x0) {
                                        pFVar1 = GetProcAddress(DAT_00fba90c,"alcCloseDevice");
                                        unaff_ESI[0x35] = pFVar1;
                                        if (pFVar1 == (FARPROC)0x0) {
                                          FID_conflict__wprintf
                                                    ("Failed to retrieve \'%s\' function address\n",
                                                     alcCloseDevice_exref);
                                          return 0;
                                        }
                                        pFVar1 = GetProcAddress(DAT_00fba90c,"alcCreateContext");
                                        unaff_ESI[0x36] = pFVar1;
                                        if (pFVar1 == (FARPROC)0x0) {
                                          FID_conflict__wprintf
                                                    ("Failed to retrieve \'%s\' function address\n",
                                                     alcCreateContext_exref);
                                          return 0;
                                        }
                                        pFVar1 = GetProcAddress(DAT_00fba90c,"alcMakeContextCurrent"
                                                               );
                                        unaff_ESI[0x37] = pFVar1;
                                        pcVar2 = alcMakeContextCurrent_exref;
                                        if (pFVar1 != (FARPROC)0x0) {
                                          pFVar1 = GetProcAddress(DAT_00fba90c,"alcProcessContext");
                                          unaff_ESI[0x38] = pFVar1;
                                          if (pFVar1 == (FARPROC)0x0) {
                                            FID_conflict__wprintf
                                                      (
                                                  "Failed to retrieve \'%s\' function address\n",
                                                  alcProcessContext_exref);
                                            return 0;
                                          }
                                          pFVar1 = GetProcAddress(DAT_00fba90c,
                                                                  "alcGetCurrentContext");
                                          unaff_ESI[0x39] = pFVar1;
                                          if (pFVar1 == (FARPROC)0x0) {
                                            FID_conflict__wprintf
                                                      (
                                                  "Failed to retrieve \'%s\' function address\n",
                                                  alcGetCurrentContext_exref);
                                            return 0;
                                          }
                                          pFVar1 = GetProcAddress(DAT_00fba90c,
                                                                  "alcGetContextsDevice");
                                          unaff_ESI[0x3a] = pFVar1;
                                          pcVar2 = alcGetContextsDevice_exref;
                                          if (pFVar1 != (FARPROC)0x0) {
                                            pFVar1 = GetProcAddress(DAT_00fba90c,"alcSuspendContext"
                                                                   );
                                            unaff_ESI[0x3b] = pFVar1;
                                            if (pFVar1 == (FARPROC)0x0) {
                                              FID_conflict__wprintf
                                                        (
                                                  "Failed to retrieve \'%s\' function address\n",
                                                  alcSuspendContext_exref);
                                              return 0;
                                            }
                                            pFVar1 = GetProcAddress(DAT_00fba90c,"alcDestroyContext"
                                                                   );
                                            unaff_ESI[0x3c] = pFVar1;
                                            if (pFVar1 == (FARPROC)0x0) {
                                              FID_conflict__wprintf
                                                        (
                                                  "Failed to retrieve \'%s\' function address\n",
                                                  alcDestroyContext_exref);
                                              return 0;
                                            }
                                            pFVar1 = GetProcAddress(DAT_00fba90c,"alcGetError");
                                            unaff_ESI[0x3d] = pFVar1;
                                            pcVar2 = alcGetError_exref;
                                            if (pFVar1 != (FARPROC)0x0) {
                                              pFVar1 = GetProcAddress(DAT_00fba90c,
                                                                      "alcIsExtensionPresent");
                                              unaff_ESI[0x3e] = pFVar1;
                                              if (pFVar1 == (FARPROC)0x0) {
                                                FID_conflict__wprintf
                                                          (
                                                  "Failed to retrieve \'%s\' function address\n",
                                                  alcIsExtensionPresent_exref);
                                                return 0;
                                              }
                                              pFVar1 = GetProcAddress(DAT_00fba90c,
                                                                      "alcGetProcAddress");
                                              unaff_ESI[0x3f] = pFVar1;
                                              if (pFVar1 == (FARPROC)0x0) {
                                                FID_conflict__wprintf
                                                          (
                                                  "Failed to retrieve \'%s\' function address\n",
                                                  alcGetProcAddress_exref);
                                                return 0;
                                              }
                                              pFVar1 = GetProcAddress(DAT_00fba90c,"alcGetEnumValue"
                                                                     );
                                              unaff_ESI[0x40] = pFVar1;
                                              pcVar2 = alcGetEnumValue_exref;
                                              if (pFVar1 != (FARPROC)0x0) {
                                                return 1;
                                              }
                                            }
                                          }
                                        }
                                      }
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
    FID_conflict__wprintf("Failed to retrieve \'%s\' function address\n",pcVar2);
  }
  return 0;
}

