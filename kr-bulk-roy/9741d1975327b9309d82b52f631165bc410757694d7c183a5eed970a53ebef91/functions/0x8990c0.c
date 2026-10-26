
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 FUN_008990c0(double param_1,double *param_2)

{
  double *pdVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  ushort in_FPUControlWord;
  float10 fVar5;
  ulonglong uVar6;
  double dVar7;
  undefined4 uVar8;
  undefined8 local_c;
  
  if ((DAT_00fe728c != 0) && ((MXCSR & 0x7f80) == 0x1f80 && (in_FPUControlWord & 0x7f) == 0x7f)) {
    uVar2 = (uint)((ulonglong)((longlong)param_1 << 1) >> 0x35);
    dVar7 = (double)(((ulonglong)param_1 >> (ulonglong)(0x433 - uVar2)) <<
                    (ulonglong)(0x433 - uVar2));
    if (uVar2 < 0x3ff) {
      *param_2 = (double)((ulonglong)param_1 & 0x8000000000000000);
      return (float10)param_1;
    }
    if (uVar2 < 0x433) {
      *param_2 = dVar7;
      return (float10)(double)((ulonglong)(param_1 - dVar7) |
                              (ulonglong)param_1 & 0x8000000000000000);
    }
    if (uVar2 != 0x7ff) {
      *param_2 = param_1;
      fVar5 = (float10)0;
      if (0x7ff < (uint)((ulonglong)param_1 >> 0x34)) {
        fVar5 = -fVar5;
      }
      return fVar5;
    }
    *param_2 = param_1 + param_1;
    uVar6 = -(ulonglong)((double)((ulonglong)(param_1 + param_1) & 0xfffffffffffff) != 0.0);
    local_c = (double)((ulonglong)param_1 & (uVar6 | 0x8000000000000000));
    if ((short)uVar6 != 0) {
      ___libm_error_support(&param_1,&param_2,&local_c,0x3ef);
      return (float10)local_c;
    }
    return (float10)local_c;
  }
  uVar3 = __ctrlfp(0,0);
  __ctrlfp(DAT_00d62b60,0xffff);
  pdVar1 = param_2;
  uVar8 = (undefined4)((ulonglong)param_1 >> 0x20);
  if ((param_1._6_2_ & 0x7ff0) == 0x7ff0) {
    *param_2 = _DAT_00d62b70;
    iVar4 = __sptype(SUB84(param_1,0),uVar8);
    uVar8 = (undefined4)((ulonglong)param_1 >> 0x20);
    if (0 < iVar4) {
      if (iVar4 < 3) {
        *pdVar1 = param_1;
        local_c = __copysign(0.0,param_1);
        __ctrlfp(uVar3,0xffff);
        goto LAB_008ae54f;
      }
      if (iVar4 == 3) {
        *pdVar1 = param_1;
        fVar5 = (float10)__handle_qnan1(0x1c,SUB84(param_1,0),uVar8,uVar3);
        return fVar5;
      }
    }
    *pdVar1 = param_1 + 1.0;
    fVar5 = (float10)__except1(8,0x1c,SUB84(param_1,0),uVar8,param_1 + 1.0,uVar3);
  }
  else {
    fVar5 = (float10)__frnd(SUB84(param_1,0),uVar8);
    *param_2 = (double)fVar5;
    dVar7 = (double)((float10)param_1 - fVar5);
    local_c = dVar7;
    if (dVar7 == 0.0) {
      local_c._6_2_ = (ushort)((ulonglong)dVar7 >> 0x30);
      local_c = (double)CONCAT26(local_c._6_2_ | param_1._6_2_ & 0x8000,SUB86(dVar7,0));
    }
    __ctrlfp(uVar3,0xffff);
LAB_008ae54f:
    fVar5 = (float10)local_c;
  }
  return fVar5;
}

