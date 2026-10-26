
void FUN_007372c0(void)

{
  int *piVar1;
  int in_ECX;
  int *piVar2;
  float local_70;
  float local_6c;
  undefined4 local_68;
  undefined4 local_64;
  float local_60;
  float local_5c;
  float local_58;
  float local_54;
  float local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  if ((((*(int *)(in_ECX + 0x24) != 0) && (*(int *)(in_ECX + 0x28) != 0)) &&
      (*(int *)(in_ECX + 0x2c) != 0)) &&
     (((piVar2 = *(int **)(in_ECX + 0x20), piVar2 != (int *)0x0 && (piVar2[0xc] != 0)) &&
      (piVar2[1] == 0)))) {
    if (*piVar2 == 3) {
      local_14 = 0;
      piVar1 = piVar2 + 4;
      local_18 = 0;
      piVar2 = piVar2 + 3;
      local_1c = 0;
      local_20 = 0;
      local_28 = 0;
      local_2c = 0;
      local_30 = 0;
      local_34 = 0;
      local_3c = 0;
      local_40 = 0;
      local_44 = 0;
      local_48 = 0;
      local_10 = 0x3f800000;
      local_24 = 0x3f800000;
      local_38 = 0x3f800000;
      local_4c = 0x3f800000;
      local_6c = (float)*(int *)(in_ECX + 8) - (float)*piVar1 * 0.5 * 1.15;
      local_70 = (float)*(int *)(in_ECX + 4) - (float)*piVar2 * 0.7 * 1.15;
      local_54 = (float)*piVar1 * 0.5 * 1.15;
      local_58 = (float)*piVar2 * 0.7 * 1.15;
      local_68 = 0x3f4e147a;
      local_64 = 0x3f133333;
      local_5c = (float)*piVar1;
      local_60 = (float)*piVar2;
      local_50 = local_5c;
      D3DXMatrixTransformation2D
                (&local_4c,&local_60,-*(float *)(in_ECX + 0x30),&local_68,&local_58,
                 *(undefined4 *)(in_ECX + 0x30),&local_70);
      (**(code **)(**(int **)(*(int *)(in_ECX + 0x20) + 0x30) + 0x40))(&local_4c,0,0,0,0xffffffff);
      __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
      return;
    }
    (**(code **)(*(int *)piVar2[0xc] + 0x20))
              (*(int *)(in_ECX + 4) - piVar2[3],*(int *)(in_ECX + 8) - piVar2[4],0,0xffffffff);
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

