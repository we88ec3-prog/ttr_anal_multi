
void FUN_00868c00(void)

{
  undefined4 *in_ECX;
  
  if (in_ECX[8] != 0) {
    FUN_00891d3d(in_ECX[8]);
    in_ECX[8] = 0;
  }
  if (in_ECX[9] != 0) {
    FUN_00891d3d(in_ECX[9]);
    in_ECX[9] = 0;
  }
  if (in_ECX[0xb] != 0) {
    FUN_00891d3d(in_ECX[0xb]);
    in_ECX[0xb] = 0;
  }
  if (in_ECX[0xc] != 0) {
    FUN_00891d3d(in_ECX[0xc]);
    in_ECX[0xc] = 0;
  }
  in_ECX[0xd] = gbLinTrack<float>::vftable;
  if (in_ECX[0x12] != 0) {
    FUN_0089120c(in_ECX[0x12]);
  }
  in_ECX[0x12] = 0;
  in_ECX[0x13] = 0;
  in_ECX[0x14] = 0;
  in_ECX[0xd] = gbTrack<float>::vftable;
  in_ECX[0xf] = gbORT::vftable;
  if (0xf < (uint)in_ECX[5]) {
    FUN_0089120c(*in_ECX);
  }
  in_ECX[4] = 0;
  in_ECX[5] = 0xf;
  *(undefined1 *)in_ECX = 0;
  return;
}

