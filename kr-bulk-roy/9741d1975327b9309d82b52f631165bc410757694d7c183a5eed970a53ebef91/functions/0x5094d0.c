
void FUN_005094d0(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  void *pvVar3;
  void *unaff_EDI;
  undefined **local_14 [3];
  char *local_8;
  
  local_8 = (char *)0x9;
  pvVar3 = unaff_EDI;
  do {
    FUN_00443d70(0x10,&LAB_0050c480);
    *(undefined2 *)((int)pvVar3 + 0x100) = 0;
    *(undefined1 *)((int)pvVar3 + 0x102) = 0;
    _memset(pvVar3,0,0x100);
    pvVar3 = (void *)((int)pvVar3 + 0x108);
    local_8 = local_8 + -1;
  } while (-1 < (int)local_8);
  pvVar3 = (void *)((int)unaff_EDI + 0xa50);
  local_8 = (char *)0x1;
  do {
    FUN_00443d70(0x20,&LAB_0050c460);
    _memset(pvVar3,0,0xca0);
    pvVar3 = (void *)((int)pvVar3 + 0xca8);
    local_8 = local_8 + -1;
  } while (-1 < (int)local_8);
  FUN_00509220();
  puVar1 = (undefined4 *)((int)unaff_EDI + 0x50c0);
  *puVar1 = 0;
  puVar2 = (undefined4 *)FUN_00891268(8);
  if (puVar2 != (undefined4 *)0x0) {
    *puVar1 = puVar2;
    *puVar2 = 0;
    puVar2[1] = 0;
    *(undefined4 **)*puVar1 = puVar1;
    *(undefined4 *)((int)unaff_EDI + 0x50c4) = 0;
    *(undefined4 *)((int)unaff_EDI + 0x50c8) = 0;
    *(undefined4 *)((int)unaff_EDI + 0x50cc) = 0;
    *(undefined4 *)((int)unaff_EDI + 0x50d0) = 0;
    *(undefined4 *)((int)unaff_EDI + 0x50dc) = 0;
    *(undefined4 *)((int)unaff_EDI + 0x50e0) = 0;
    *(undefined4 *)((int)unaff_EDI + 0x50e4) = 0;
    *(undefined4 *)((int)unaff_EDI + 0x50e8) = 0;
    *(undefined4 *)((int)unaff_EDI + 0x50f0) = 0;
    return;
  }
  local_8 = (char *)0x0;
  std::exception::exception((exception *)local_14,&local_8);
  local_14[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_14,&DAT_00c857a8);
}

