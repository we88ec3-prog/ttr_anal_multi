
void FUN_006f0e70(void)

{
  HANDLE pvVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int in_ECX;
  
  if (*(int *)(in_ECX + 100) == 0) {
    *(undefined1 *)(in_ECX + 0x1a8) = 0;
    pvVar1 = CreateEventA((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCSTR)0x0);
    *(HANDLE *)(in_ECX + 0x6c) = pvVar1;
    pvVar1 = CreateEventA((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCSTR)0x0);
    *(HANDLE *)(in_ECX + 0x70) = pvVar1;
    FUN_006f0db0();
    puVar2 = (undefined4 *)FUN_00891268(0xc);
    if (puVar2 != (undefined4 *)0x0) {
      *puVar2 = FunctorArg0Inst<void,CLogBackend_Type2>::vftable;
      puVar2[1] = in_ECX;
      puVar2[2] = FUN_006f09c0;
      uVar3 = FUN_004fb770();
      *(undefined4 *)(in_ECX + 100) = uVar3;
      return;
    }
    uVar3 = FUN_004fb770();
    *(undefined4 *)(in_ECX + 100) = uVar3;
  }
  return;
}

