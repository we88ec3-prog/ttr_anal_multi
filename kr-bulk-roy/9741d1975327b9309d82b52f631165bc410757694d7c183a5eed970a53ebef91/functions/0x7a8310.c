
void FUN_007a8310(void)

{
  float fVar1;
  float *pfVar2;
  int iVar3;
  undefined4 uVar4;
  int in_ECX;
  float10 fVar5;
  float fStack_54;
  float fStack_50;
  float local_4c;
  float local_48;
  float local_44;
  float local_40;
  float local_3c;
  float fStack_38;
  undefined8 uStack_2c;
  float local_24;
  float local_20;
  undefined1 auStack_1c [16];
  uint local_c;
  
  local_c = DAT_00d61f20 ^ (uint)&fStack_54;
  if (((*(int *)(in_ECX + 0xa0) == 0) || (*(int *)(in_ECX + 0x10) == 0)) ||
     (*(int *)(*(int *)(in_ECX + 0x10) + 0x14) == 0)) {
    iVar3 = *(int *)(in_ECX + 0x10);
    if (iVar3 != 0) {
      uStack_2c._4_4_ = *(float *)(iVar3 + 0x28);
      local_24 = *(float *)(iVar3 + 0x2c);
      local_20 = *(float *)(iVar3 + 0x30);
      fVar5 = (float10)FUN_007a7100();
      local_44 = (float)(fVar5 * (float10)0.5 + (float10)local_20);
      local_4c = uStack_2c._4_4_;
      local_48 = local_24;
      local_20 = local_44;
      goto LAB_007a83a4;
    }
    iVar3 = *(int *)(in_ECX + 0x150);
    if ((iVar3 != 0) &&
       (((*(float *)(iVar3 + 0x1c) != local_4c || (*(float *)(iVar3 + 0x20) != local_48)) ||
        ((*(float *)(iVar3 + 0x24) != local_44 || (*(float *)(iVar3 + 0x40) != 10.0)))))) {
      FUN_007d7300();
      FUN_0089120c(iVar3);
      *(undefined4 *)(in_ECX + 0x150) = 0;
    }
    if (*(int *)(in_ECX + 0x150) != 0) goto LAB_007a8601;
    uStack_2c._4_4_ = 10.0;
    uVar4 = 0;
  }
  else {
    (**(code **)(**(int **)(in_ECX + 0xa0) + 0x40))();
    pfVar2 = (float *)FUN_007d4430();
    local_44 = pfVar2[2];
    local_4c = *pfVar2;
    local_48 = pfVar2[1];
LAB_007a83a4:
    local_40 = local_4c;
    local_3c = local_48;
    iVar3 = (**(code **)(*(int *)(in_ECX + -8) + 8))((int)&uStack_2c + 4);
    local_3c = *(float *)(iVar3 + 8);
    fVar5 = (float10)FUN_007a7100();
    fStack_54 = (float)fVar5;
    uStack_2c = (double)local_48;
    iVar3 = (**(code **)(*(int *)(in_ECX + -8) + 8))(auStack_1c);
    if (fStack_50 <= 0.0) {
      fStack_50 = 1.0;
    }
    fVar1 = fStack_50 * 0.5;
    uStack_2c._4_4_ =
         ((((float)(double)CONCAT44(local_24,uStack_2c._4_4_) - *(float *)(iVar3 + 8)) - fVar1) /
         fVar1) * 0.5 + 1.0;
    fStack_50 = 2.5 - uStack_2c._4_4_;
    if (fStack_50 <= 0.8) {
      if (fStack_50 < 0.1) {
        fStack_50 = 0.1;
      }
    }
    else {
      fStack_50 = 0.8;
    }
    iVar3 = *(int *)(in_ECX + 0x150);
    fStack_50 = fVar1 * fStack_50 * 0.25 * 10.0;
    if (iVar3 != 0) {
      fVar1 = local_4c - *(float *)(iVar3 + 0x1c);
      local_24 = local_48 - *(float *)(iVar3 + 0x20);
      local_20 = fStack_38 - *(float *)(iVar3 + 0x24);
      uStack_2c._4_4_ = local_20 * local_20 + fVar1 * fVar1 + local_24 * local_24;
      if (uStack_2c._4_4_ <= 0.01) {
        uStack_2c._4_4_ = fStack_50 - *(float *)(iVar3 + 0x40);
        fVar5 = (float10)FUN_004ff540(uStack_2c._4_4_);
        if (fVar5 <= (float10)0.20000000298023224) goto LAB_007a853f;
      }
      FUN_007d7300();
      FUN_0089120c(iVar3);
      *(undefined4 *)(in_ECX + 0x150) = 0;
    }
LAB_007a853f:
    if (*(int *)(in_ECX + 0x150) != 0) goto LAB_007a8601;
    uVar4 = *(undefined4 *)(in_ECX + 0xf0);
  }
  uVar4 = FUN_007baa80(DAT_00fba838,uVar4);
  *(undefined4 *)(in_ECX + 0x150) = uVar4;
LAB_007a8601:
  if (*(int *)(in_ECX + 0x150) != 0) {
    FUN_007e8240(*(undefined4 *)(DAT_00fba838 + 0x8c),*(int *)(in_ECX + 0x150));
  }
  __security_check_cookie(local_c ^ (uint)&fStack_54);
  return;
}

