
undefined4 * FUN_007f3a70(void)

{
  int *piVar1;
  longlong lVar2;
  undefined4 *puVar3;
  void *pvVar4;
  void *_Dst;
  void *pvVar5;
  int *unaff_EDI;
  
  puVar3 = (undefined4 *)FUN_00891268(0x1c);
  piVar1 = (int *)*unaff_EDI;
  pvVar5 = (void *)0x0;
  if ((void *)*piVar1 != (void *)0x0) {
    pvVar5 = (void *)*piVar1;
  }
  pvVar4 = (void *)FUN_0087dc3d(piVar1[4] * piVar1[3]);
  puVar3[1] = pvVar4;
  FID_conflict__memcpy(pvVar4,pvVar5,*(int *)(*unaff_EDI + 0x10) * *(int *)(*unaff_EDI + 0xc));
  puVar3[3] = 0;
  puVar3[4] = 0;
  puVar3[5] = 0;
  lVar2 = (ulonglong)*(uint *)(*unaff_EDI + 8) * 2;
  _Dst = (void *)FUN_0087dc3d(-(uint)((int)((ulonglong)lVar2 >> 0x20) != 0) | (uint)lVar2);
  puVar3[2] = _Dst;
  pvVar5 = *(void **)(*unaff_EDI + 4);
  pvVar4 = (void *)0x0;
  if (pvVar5 != (void *)0x0) {
    pvVar4 = pvVar5;
  }
  FID_conflict__memcpy(_Dst,pvVar4,*(int *)(*unaff_EDI + 8) * 2);
  *puVar3 = unaff_EDI;
  return puVar3;
}

