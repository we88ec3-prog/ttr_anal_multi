
uintptr_t * FUN_004fb770(void)

{
  uintptr_t *puVar1;
  uintptr_t uVar2;
  void *unaff_EDI;
  
  puVar1 = (uintptr_t *)FUN_00891268(0xc);
  if (puVar1 == (uintptr_t *)0x0) {
    puVar1 = (uintptr_t *)0x0;
  }
  else {
    *puVar1 = 0xffffffff;
    puVar1[1] = 0;
    puVar1[2] = 0;
  }
  puVar1[2] = (uintptr_t)unaff_EDI;
  uVar2 = __beginthreadex((void *)0x0,0,FUN_004fb740,unaff_EDI,0,puVar1 + 1);
  *puVar1 = uVar2;
  if (uVar2 != 0xffffffff) {
    return puVar1;
  }
  FUN_004fb7d0();
  return (uintptr_t *)0x0;
}

