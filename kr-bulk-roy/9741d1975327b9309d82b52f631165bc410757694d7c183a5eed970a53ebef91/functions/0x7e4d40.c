
undefined4 *
FUN_007e4d40(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  char cVar1;
  uint uVar2;
  undefined4 *puVar3;
  char *pcVar4;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00904753;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  param_1[1] = IS3D::IRenderable::vftable;
  local_8 = 1;
  *param_1 = IS3D::CFieldGeometry::vftable;
  param_1[1] = IS3D::CFieldGeometry::vftable;
  param_1[2] = 0;
  param_1[3] = 0;
  puVar3 = (undefined4 *)FUN_00891268(0x14,uVar2);
  if (puVar3 == (undefined4 *)0x0) {
    puVar3 = (undefined4 *)0x0;
  }
  else {
    *puVar3 = 0;
    puVar3[1] = 0;
    puVar3[2] = 0;
    puVar3[3] = 0;
    puVar3[4] = 0;
  }
  param_1[9] = puVar3;
  param_1[10] = 1;
  param_1[0x52] = 0;
  param_1[0x53] = 0;
  param_1[0x56] = 0;
  param_1[0x57] = 0;
  param_1[0x58] = param_3;
  param_1[0x5a] = param_2;
  param_1[0x59] = param_4;
  param_1[0x5b] = 0;
  param_1[0x5c] = 0;
  param_1[0x5d] = 0;
  param_1[0x5e] = 0;
  param_1[0x5f] = 0;
  puVar3 = (undefined4 *)FUN_00891268(0x34,uVar2);
  if (puVar3 == (undefined4 *)0x0) {
    puVar3 = (undefined4 *)0x0;
  }
  else {
    puVar3[0xc] = 7;
    _memset(puVar3,0,0x34);
    puVar3[8] = 0x3f800000;
    puVar3[4] = 0x3f800000;
    *puVar3 = 0x3f800000;
  }
  param_1[0x60] = puVar3;
  param_1[0x61] = 0;
  param_1[0x62] = 0;
  param_1[99] = 0;
  pcVar4 = "Map/";
  param_1[0x66] = 0;
  param_1[0x67] = 0;
  param_1[0x55] = 0;
  param_1[0x54] = 0;
  do {
    cVar1 = *pcVar4;
    *(char *)((int)(param_1 + -0x3033a7) + (int)pcVar4) = cVar1;
    pcVar4 = pcVar4 + 1;
  } while (cVar1 != '\0');
  ExceptionList = local_10;
  return param_1;
}

