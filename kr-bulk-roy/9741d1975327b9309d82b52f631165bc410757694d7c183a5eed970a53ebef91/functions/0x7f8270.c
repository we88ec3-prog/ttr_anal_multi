
void FUN_007f8270(void)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *unaff_ESI;
  undefined1 local_14 [4];
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_009348ce;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00fb79e8 & 1) == 0) {
    DAT_00fb79e8 = DAT_00fb79e8 | 1;
    local_8 = 0;
    FUN_00798de0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit((_func_4879 *)&LAB_00bcd2e0);
  }
  local_8 = 0xffffffff;
  uVar2 = FUN_0079a5f0(&DAT_00fb76a8);
  puVar1 = unaff_ESI + 1;
  iVar3 = D3DXCreateEffectFromFileW(uVar2,L"Material/splatting.obj",0,0,0x400,0,puVar1,local_14);
  if (iVar3 < 0) {
    *unaff_ESI = 0;
    ExceptionList = local_10;
    return;
  }
  *unaff_ESI = 1;
  uVar2 = (**(code **)(*(int *)*puVar1 + 0x34))((int *)*puVar1,"Splatting_CH4");
  unaff_ESI[2] = uVar2;
  uVar2 = (**(code **)(*(int *)*puVar1 + 0x24))((int *)*puVar1,0,"diffuseCh0");
  unaff_ESI[0x18] = uVar2;
  uVar2 = (**(code **)(*(int *)*puVar1 + 0x24))((int *)*puVar1,0,"diffuseCh1");
  unaff_ESI[0x19] = uVar2;
  uVar2 = (**(code **)(*(int *)*puVar1 + 0x24))((int *)*puVar1,0,"diffuseCh2");
  unaff_ESI[0x1a] = uVar2;
  uVar2 = (**(code **)(*(int *)*puVar1 + 0x24))((int *)*puVar1,0,"diffuseCh3");
  unaff_ESI[0x1b] = uVar2;
  uVar2 = (**(code **)(*(int *)*puVar1 + 0x24))((int *)*puVar1,0,"alphaTexture");
  unaff_ESI[0x20] = uVar2;
  uVar2 = (**(code **)(*(int *)*puVar1 + 0x24))((int *)*puVar1,0,"texMatrix");
  unaff_ESI[5] = uVar2;
  uVar2 = (**(code **)(*(int *)*puVar1 + 0x24))((int *)*puVar1,0,"texMatrix_ch0");
  unaff_ESI[0x1c] = uVar2;
  uVar2 = (**(code **)(*(int *)*puVar1 + 0x24))((int *)*puVar1,0,"texMatrix_ch1");
  unaff_ESI[0x1d] = uVar2;
  uVar2 = (**(code **)(*(int *)*puVar1 + 0x24))((int *)*puVar1,0,"texMatrix_ch2");
  unaff_ESI[0x1e] = uVar2;
  uVar2 = (**(code **)(*(int *)*puVar1 + 0x24))((int *)*puVar1,0,"texMatrix_ch3");
  unaff_ESI[0x1f] = uVar2;
  uVar2 = (**(code **)(*(int *)*puVar1 + 0x24))((int *)*puVar1,0,"worldSize");
  unaff_ESI[4] = uVar2;
  uVar2 = (**(code **)(*(int *)*puVar1 + 0x24))((int *)*puVar1,0,"lightmapTexture");
  unaff_ESI[0x29] = uVar2;
  ExceptionList = local_10;
  return;
}

