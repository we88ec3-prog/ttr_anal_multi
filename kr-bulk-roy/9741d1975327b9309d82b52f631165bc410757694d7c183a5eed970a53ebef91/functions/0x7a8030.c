
void FUN_007a8030(undefined4 param_1)

{
  int iVar1;
  float fVar2;
  float *pfVar3;
  float fVar4;
  float fVar5;
  int unaff_EDI;
  float10 fVar6;
  float local_40;
  undefined1 local_24 [12];
  float local_18;
  float local_14;
  float local_10;
  uint local_c;
  
  local_c = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  if (((*(int *)(unaff_EDI + 0xac) == 0) || (*(int *)(unaff_EDI + 0x1c) == 0)) ||
     (*(int *)(*(int *)(unaff_EDI + 0x1c) + 0x14) == 0)) {
    iVar1 = *(int *)(unaff_EDI + 0x1c);
    if (iVar1 == 0) {
      pfVar3 = (float *)(**(code **)(*(int *)(unaff_EDI + 4) + 8))(local_24);
      fVar5 = *pfVar3;
      fVar4 = pfVar3[1];
      local_40 = pfVar3[2];
    }
    else {
      fVar4 = *(float *)(iVar1 + 0x2c);
      fVar5 = *(float *)(iVar1 + 0x28);
      fVar2 = *(float *)(iVar1 + 0x30);
      fVar6 = (float10)FUN_007a7100();
      local_40 = (float)(fVar6 * (float10)0.5 + (float10)fVar2);
    }
  }
  else {
    (**(code **)(**(int **)(unaff_EDI + 0xac) + 0x40))();
    pfVar3 = (float *)FUN_007d4430();
    local_40 = pfVar3[2];
    fVar5 = *pfVar3;
    fVar4 = pfVar3[1];
  }
  (**(code **)(*(int *)(unaff_EDI + 4) + 8))(&local_18);
  fVar6 = (float10)FUN_007a7100();
  fVar2 = (float)(fVar6 * (float10)0.5 + (float10)local_40) - local_10;
  FUN_007cb770(param_1);
  fVar6 = (float10)FUN_007a7100();
  fVar6 = (float10)FUN_007cb860(&local_18,
                                fVar2 * fVar2 +
                                (fVar4 - local_14) * (fVar4 - local_14) +
                                (fVar5 - local_18) * (fVar5 - local_18),
                                (float)(fVar6 * (float10)0.30000001192092896));
  if ((float10)0.0 <= fVar6) {
    __security_check_cookie(local_c ^ (uint)&stack0xfffffffc);
    return;
  }
  __security_check_cookie(local_c ^ (uint)&stack0xfffffffc);
  return;
}

