
undefined4 FUN_00807a70(void *param_1,size_t param_2)

{
  uint uVar1;
  int *piVar2;
  LPCRITICAL_SECTION lpCriticalSection;
  int *piVar3;
  undefined4 *unaff_EDI;
  undefined4 local_8;
  
  lpCriticalSection = (LPCRITICAL_SECTION)*unaff_EDI;
  EnterCriticalSection(lpCriticalSection);
  uVar1 = param_2 + 4;
  local_8 = CONCAT22(0x1a68,(short)param_2);
  if (((0x1000 < uVar1) || (param_2 == 0)) || (0x4000 < unaff_EDI[0x1403] + uVar1)) {
    LeaveCriticalSection(lpCriticalSection);
    return 0;
  }
  piVar3 = (int *)unaff_EDI[0x1401];
  piVar2 = unaff_EDI + 0x1401;
  if (((unaff_EDI + 1 <= piVar3) && (piVar3 < piVar2)) &&
     ((unaff_EDI + 1 <= (int *)((int)piVar3 + uVar1) && ((int *)((int)piVar3 + uVar1) < piVar2)))) {
    *piVar3 = local_8;
    FID_conflict__memcpy((void *)(*piVar2 + 4),param_1,param_2);
    unaff_EDI[0x1403] = unaff_EDI[0x1403] + uVar1;
    *piVar2 = *piVar2 + uVar1;
    LeaveCriticalSection(lpCriticalSection);
    return 1;
  }
  LeaveCriticalSection(lpCriticalSection);
  return 0;
}

