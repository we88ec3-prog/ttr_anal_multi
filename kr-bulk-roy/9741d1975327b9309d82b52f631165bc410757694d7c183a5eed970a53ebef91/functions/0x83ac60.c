
void FUN_0083ac60(int param_1)

{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  int in_ECX;
  undefined4 unaff_EBX;
  uint uVar4;
  int iVar5;
  int *piStack_a8;
  float *local_a4;
  uint uVar6;
  longlong lStack_98;
  undefined1 auStack_94 [4];
  undefined4 local_90;
  undefined4 local_8c;
  undefined4 local_88;
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  float local_60;
  float local_5c;
  float local_58;
  float fStack_54;
  uint uStack_20;
  undefined4 local_18;
  uint local_c;
  
  local_c = DAT_00d61f20 ^ (uint)auStack_94;
  lStack_98 = CONCAT44(auStack_94,unaff_EBX);
  local_88 = *(undefined4 *)(param_1 + 0x1a8);
  local_90 = *(undefined4 *)(param_1 + 0x1a0);
  local_8c = *(undefined4 *)(param_1 + 0x1a4);
  local_78 = *(undefined4 *)(param_1 + 0x1b0);
  local_74 = *(undefined4 *)(param_1 + 0x1b4);
  local_7c = *(undefined4 *)(param_1 + 0x1ac);
  local_60 = *(float *)(param_1 + 0x1bc);
  local_5c = *(float *)(param_1 + 0x1c0);
  local_64 = *(undefined4 *)(param_1 + 0x1b8);
  local_6c = *(undefined4 *)(param_1 + 0x198);
  local_68 = *(undefined4 *)(param_1 + 0x19c);
  local_70 = *(undefined4 *)(param_1 + 0x194);
  local_a4 = (float *)0x3f800000;
  piStack_a8 = (int *)0x83ad0d;
  FUN_00839530();
  local_a4 = *(float **)(param_1 + 0x1cc);
  piStack_a8 = (int *)0x83ad23;
  FUN_00839530();
  local_a4 = (float *)0x3f800000;
  piStack_a8 = (int *)0x83ad35;
  FUN_00839530();
  local_a4 = (float *)0x3f800000;
  piStack_a8 = (int *)0x83ad47;
  FUN_00839530();
  local_18 = *(undefined4 *)(param_1 + 0x1c4);
  piStack_a8 = *(int **)(in_ECX + 0xec);
  local_a4 = &local_58;
  (**(code **)(*piStack_a8 + 0xc4))();
  uVar6 = (uint)(longlong)ROUND(local_60 * 255.0);
  uVar4 = uVar6 & 0xff;
  uVar6 = (uint)(longlong)ROUND(fStack_54 * 255.0);
  uVar1 = uVar6 << 8;
  uVar6 = (uint)(longlong)ROUND(local_5c * 255.0);
  uVar2 = uVar6 & 0xff;
  lStack_98 = (longlong)ROUND(local_58 * 255.0);
  (**(code **)(**(int **)(in_ECX + 0xec) + 0xe4))
            (*(int **)(in_ECX + 0xec),0x3c,((uVar4 | uVar1) << 8 | uVar2) << 8 | uVar6 & 0xff);
  local_a4 = *(float **)(param_1 + 0x178);
  iVar5 = 0;
  if (0 < (int)local_a4) {
    do {
      uVar3 = FUN_00843ef0();
      FUN_0083af10(in_ECX,iVar5,uVar3);
      iVar5 = iVar5 + 1;
    } while (iVar5 < (int)local_a4);
  }
  __security_check_cookie(uStack_20 ^ (uint)&piStack_a8);
  return;
}

