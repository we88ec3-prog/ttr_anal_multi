
void FUN_007baa80(int param_1,float param_2)

{
  int iVar1;
  float *in_ECX;
  float *in_EDX;
  uint uVar2;
  undefined4 local_484;
  undefined4 local_480;
  undefined4 local_47c;
  float local_478;
  float local_474;
  float *local_470;
  float *local_46c;
  float local_468;
  float local_464;
  int local_460;
  undefined1 local_45c [68];
  undefined4 local_418;
  undefined4 local_414;
  undefined4 local_410;
  undefined1 local_40c [1028];
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  if (*(int *)(param_1 + 0x40) != 0) {
    local_468 = *(float *)(*(int *)(param_1 + 0x40) + 0x16c);
    local_464 = *(float *)(*(int *)(param_1 + 0x40) + 0x170);
    if ((local_468 != 0.0) && (local_464 != 0.0)) {
      local_418 = 0x3f800000;
      local_414 = 0;
      local_410 = 0;
      local_470 = in_ECX;
      local_46c = in_EDX;
      if (param_2 != 0.0) {
        D3DXMatrixRotationZ(local_45c,param_2);
        D3DXVec3TransformCoord(&local_418,&local_418,local_45c);
      }
      local_460 = FUN_00891268(0x3ed0);
      if (local_460 == 0) {
        local_460 = 0;
      }
      else {
        *(undefined4 *)(local_460 + 0x3ec4) = 0xf;
        *(undefined4 *)(local_460 + 0x3ec0) = 0;
        *(undefined1 *)(local_460 + 0x3eb0) = 0;
        *(undefined4 *)(local_460 + 0x3ecc) = 0;
      }
      local_484 = 0;
      local_480 = 0;
      local_47c = 0x3f800000;
      local_474 = *in_EDX * 0.5;
      FUN_007d7360(in_ECX,&local_484,*in_EDX,*in_EDX,local_474);
      local_478 = *local_470;
      local_474 = local_470[1];
      FUN_007e76b0(local_40c,0x200,&local_46c);
      FUN_007d7740(local_46c,local_40c,local_464);
      iVar1 = *(int *)(param_1 + 200);
      uVar2 = 0;
      if (*(int *)(param_1 + 0xcc) - iVar1 >> 2 != 0) {
        do {
          iVar1 = *(int *)(iVar1 + uVar2 * 4);
          local_464 = *local_470;
          local_468 = local_470[1];
          if ((((*(float *)(iVar1 + 8) <= local_468) && (local_468 <= *(float *)(iVar1 + 0x10))) &&
              (*(float *)(iVar1 + 4) <= local_464)) && (local_464 <= *(float *)(iVar1 + 0xc))) {
            FUN_007d7740((*(int *)(iVar1 + 0x38) - *(int *)(iVar1 + 0x34)) / 6,
                         *(int *)(iVar1 + 0x34),*(undefined4 *)(iVar1 + 0x24));
          }
          iVar1 = *(int *)(param_1 + 200);
          uVar2 = uVar2 + 1;
        } while (uVar2 < (uint)(*(int *)(param_1 + 0xcc) - iVar1 >> 2));
      }
      __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
      return;
    }
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

