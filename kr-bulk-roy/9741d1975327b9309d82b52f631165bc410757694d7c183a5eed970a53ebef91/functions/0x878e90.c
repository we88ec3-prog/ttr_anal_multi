
/* WARNING: Removing unreachable block (ram,0x00878eaa) */
/* WARNING: Removing unreachable block (ram,0x00878eb0) */

void FUN_00878e90(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = gbParticleTrack::vftable;
  if (in_ECX[10] != in_ECX[0xb]) {
    in_ECX[0xb] = in_ECX[10];
  }
  if (in_ECX[10] != 0) {
    FUN_0089120c(in_ECX[10]);
  }
  in_ECX[10] = 0;
  in_ECX[0xb] = 0;
  in_ECX[0xc] = 0;
  in_ECX[1] = gbLinTrack<gbVec3<float>_>::vftable;
  if (in_ECX[6] != 0) {
    FUN_0089120c(in_ECX[6]);
  }
  in_ECX[6] = 0;
  in_ECX[7] = 0;
  in_ECX[8] = 0;
  in_ECX[1] = gbTrack<gbVec3<float>_>::vftable;
  in_ECX[3] = gbORT::vftable;
  return;
}

