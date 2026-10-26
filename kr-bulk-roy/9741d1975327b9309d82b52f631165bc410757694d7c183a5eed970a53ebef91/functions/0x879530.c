
void FUN_00879530(void)

{
  undefined4 *in_EAX;
  
  in_EAX[1] = 0xa1241010;
  *in_EAX = gbParticleSphereVolume::vftable;
  in_EAX[4] = gbParticleTrack::vftable;
  in_EAX[7] = gbORT::vftable;
  in_EAX[8] = 1;
  in_EAX[9] = 1;
  in_EAX[5] = gbLinTrack<gbVec3<float>_>::vftable;
  in_EAX[10] = 0;
  in_EAX[0xb] = 0;
  in_EAX[0xc] = 0;
  in_EAX[6] = 2;
  in_EAX[0xe] = 0;
  in_EAX[0xf] = 0;
  in_EAX[0x10] = 0;
  in_EAX[0x12] = 1;
  in_EAX[2] = 0;
  in_EAX[3] = 0;
  return;
}

