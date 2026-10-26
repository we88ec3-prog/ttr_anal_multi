
/* WARNING: Type propagation algorithm not settling */

void FUN_005756d0(undefined4 param_1)

{
  float fVar1;
  char cVar2;
  float *pfVar3;
  int iVar4;
  int *unaff_ESI;
  float local_28 [3];
  float local_1c [4];
  uint local_c;
  
  local_c = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  local_1c[0] = 0.0;
  local_1c[1] = 0.0;
  iVar4 = *unaff_ESI;
  local_1c[2] = 8.96831e-44;
  local_1c[3] = 8.96831e-44;
  local_28[0] = (float)FUN_00575df0(param_1);
  if (local_28[0] != *(float *)(iVar4 + 4)) {
    cVar2 = FUN_005436a0();
    if (cVar2 == '\0') {
      pfVar3 = local_28;
      goto LAB_00575726;
    }
  }
  local_28[2] = *(float *)(iVar4 + 4);
  pfVar3 = local_28 + 2;
LAB_00575726:
  fVar1 = *pfVar3;
  if (fVar1 != *(float *)(*unaff_ESI + 4)) {
    iVar4 = (**(code **)(**(int **)((int)fVar1 + 0x2c) + 0x10))();
    if (iVar4 != 0) {
      local_28[1] = 0.0;
      local_28[2] = (float)(unaff_ESI[6] << 6);
      (**(code **)(**(int **)((int)fVar1 + 0x2c) + 0x34))(local_28 + 1,local_1c,0xffffffff);
    }
  }
  unaff_ESI[6] = unaff_ESI[6] + 1;
  __security_check_cookie(local_c ^ (uint)&stack0xfffffffc);
  return;
}

