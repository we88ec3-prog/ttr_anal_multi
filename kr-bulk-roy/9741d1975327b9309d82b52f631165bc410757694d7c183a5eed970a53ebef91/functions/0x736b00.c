
void FUN_00736b00(undefined4 param_1)

{
  uint uVar1;
  int *piVar2;
  undefined4 uVar3;
  int in_ECX;
  int *local_44 [2];
  undefined4 local_3c;
  undefined4 local_2c;
  uint local_28;
  int *local_20;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_0090f173;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)local_44;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xffffffb0;
  ExceptionList = &local_14;
  FUN_00736f40(local_44);
  if (local_44[0] == *(int **)(in_ECX + 0xc)) {
    piVar2 = (int *)FUN_00891268(0x4c,uVar1);
    local_c = 0;
    local_44[0] = piVar2;
    if (piVar2 == (int *)0x0) {
      piVar2 = (int *)0x0;
    }
    else {
      FUN_0073b090(piVar2);
      *piVar2 = (int)Graphics::CSimpleTexture::vftable;
      piVar2[1] = (int)Graphics::CSimpleTexture::vftable;
      piVar2[2] = (int)Graphics::CSimpleTexture::vftable;
      piVar2[0x11] = 0;
      piVar2[0x12] = 0;
    }
    local_c = 0xffffffff;
    (**(code **)(piVar2[1] + 4))();
    (**(code **)(piVar2[2] + 4))();
    local_3c = (uint)local_3c._2_2_ << 0x10;
    local_28 = 7;
    local_2c = 0;
    FUN_004026e0(param_1,0,0xffffffff);
    local_c = 1;
    local_20 = piVar2;
    uVar3 = FUN_00737130(&local_3c);
    FUN_0044fb30(in_ECX + 8,local_44,uVar3);
    local_c = 0xffffffff;
    if (7 < local_28) {
      FUN_0089120c(local_3c);
    }
    local_3c = local_3c & 0xffff0000;
    local_28 = 7;
    local_2c = 0;
    (**(code **)(*piVar2 + 4))();
  }
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)local_44);
  return;
}

