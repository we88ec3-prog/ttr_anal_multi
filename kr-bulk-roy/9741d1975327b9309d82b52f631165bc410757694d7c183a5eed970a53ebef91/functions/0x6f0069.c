
_Collvec FUN_006f0069(void)

{
  char cVar1;
  undefined1 uVar2;
  undefined4 *puVar3;
  wchar_t *pwVar4;
  undefined4 in_EAX;
  undefined1 *puVar5;
  undefined1 *in_ECX;
  undefined1 *puVar6;
  int unaff_EBX;
  int unaff_EBP;
  undefined1 *unaff_ESI;
  undefined1 *puVar7;
  int unaff_EDI;
  int iVar8;
  _Collvec _Var9;
  
  while( true ) {
    unaff_EDI = unaff_EDI + -1;
    in_ECX = in_ECX + 1;
    unaff_ESI = unaff_ESI + 1;
    if (unaff_EDI == 0) break;
    *in_ECX = *unaff_ESI;
  }
  *(undefined4 *)(unaff_EBX + 0x10) = in_EAX;
  __Getcoll();
  puVar7 = &DAT_00bf943c;
  puVar5 = (undefined1 *)FUN_0087dc3d(5);
  puVar6 = puVar5;
  for (iVar8 = 5; iVar8 != 0; iVar8 = iVar8 + -1) {
    *puVar6 = *puVar7;
    puVar6 = puVar6 + 1;
    puVar7 = puVar7 + 1;
  }
  *(undefined1 **)(unaff_EBX + 0x14) = puVar5;
  __Getcoll();
  puVar3 = *(undefined4 **)(unaff_EBP + -0x14);
  *(undefined1 *)(unaff_EBX + 0xc) = *(undefined1 *)*puVar3;
  _Var9 = __Getcoll();
  cVar1 = *(char *)(unaff_EBP + 0xc);
  pwVar4 = (wchar_t *)puVar3[1];
  uVar2 = (undefined1)*pwVar4;
  _Var9._Page._1_3_ = _Var9._Page._1_3_;
  _Var9._Page._0_1_ = uVar2;
  _Var9._LocaleName = pwVar4;
  *(undefined1 *)(unaff_EBX + 0xd) = uVar2;
  if (cVar1 != '\0') {
    __Getcoll();
    *(undefined1 *)(unaff_EBX + 0xc) = 0x2e;
    _Var9 = __Getcoll();
    *(undefined1 *)(unaff_EBX + 0xd) = 0x2c;
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return _Var9;
}

