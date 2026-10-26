
void FUN_006d8d20(void)

{
  undefined4 in_EAX;
  HANDLE pvVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 *unaff_ESI;
  
  *unaff_ESI = AlarmedThread::vftable;
  unaff_ESI[1] = 0;
  unaff_ESI[2] = 0;
  unaff_ESI[3] = 0xffffffff;
  unaff_ESI[4] = 0;
  unaff_ESI[5] = in_EAX;
  pvVar1 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
  unaff_ESI[3] = pvVar1;
  unaff_ESI[2] = 1;
  puVar2 = (undefined4 *)FUN_00891268(0xc);
  if (puVar2 != (undefined4 *)0x0) {
    *puVar2 = FunctorArg0Inst<void,AlarmedThread>::vftable;
    puVar2[1] = unaff_ESI;
    puVar2[2] = FUN_006d8da0;
  }
  iVar3 = FUN_004fb770();
  unaff_ESI[1] = iVar3;
  FUN_006d8c40(*(undefined4 *)(iVar3 + 4));
  return;
}

