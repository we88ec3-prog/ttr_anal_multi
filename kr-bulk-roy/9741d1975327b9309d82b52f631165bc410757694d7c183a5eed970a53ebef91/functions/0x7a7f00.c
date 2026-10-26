
void FUN_007a7f00(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *in_ECX;
  undefined4 uVar3;
  int unaff_EDI;
  float10 fVar4;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  float local_34;
  undefined4 local_2c;
  float local_28;
  undefined4 local_24;
  undefined4 local_20;
  float local_1c;
  undefined1 local_18 [12];
  uint local_c;
  
  local_c = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  local_4c = *param_1;
  local_48 = param_1[1];
  local_44 = param_1[2];
  local_40 = *in_ECX;
  local_3c = in_ECX[1];
  local_38 = in_ECX[2];
  local_24 = local_40;
  local_20 = local_3c;
  local_1c = (float)local_38;
  if (((*(int *)(unaff_EDI + 0xac) == 0) || (*(int *)(unaff_EDI + 0x1c) == 0)) ||
     (*(int *)(*(int *)(unaff_EDI + 0x1c) + 0x14) == 0)) {
    iVar1 = *(int *)(unaff_EDI + 0x1c);
    if (iVar1 != 0) {
      local_2c = *(undefined4 *)(iVar1 + 0x2c);
      local_28 = *(float *)(iVar1 + 0x30);
      uVar3 = *(undefined4 *)(iVar1 + 0x28);
      fVar4 = (float10)FUN_007a7100();
      local_20 = local_2c;
      local_28 = (float)(fVar4 * (float10)0.5 + (float10)local_28);
      local_1c = local_28;
      goto LAB_007a7fdf;
    }
    puVar2 = (undefined4 *)(**(code **)(*(int *)(unaff_EDI + 4) + 8))(local_18);
  }
  else {
    (**(code **)(**(int **)(unaff_EDI + 0xac) + 0x40))();
    puVar2 = (undefined4 *)FUN_007d4430();
  }
  local_1c = (float)puVar2[2];
  local_20 = puVar2[1];
  uVar3 = *puVar2;
LAB_007a7fdf:
  fVar4 = (float10)FUN_007a7100();
  local_34 = (float)(fVar4 * (float10)0.6000000238418579);
  FUN_007cb600(&local_4c,uVar3,local_20,local_1c,local_34);
  __security_check_cookie(local_c ^ (uint)&stack0xfffffffc);
  return;
}

