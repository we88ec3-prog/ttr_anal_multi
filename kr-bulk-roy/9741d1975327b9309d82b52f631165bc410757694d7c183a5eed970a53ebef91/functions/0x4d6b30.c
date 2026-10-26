
void FUN_004d6b30(undefined4 param_1)

{
  undefined4 *puVar1;
  int unaff_EDI;
  
  puVar1 = (undefined4 *)FUN_00891268(0x24);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    puVar1[7] = 7;
    puVar1[6] = 0;
    *(undefined2 *)(puVar1 + 2) = 0;
  }
  *puVar1 = 0;
  *(undefined1 *)(puVar1 + 1) = 1;
  FUN_004026e0(param_1,0,0xffffffff);
  FUN_004d7b00(unaff_EDI);
  if (*(int *)(unaff_EDI + 0x120) == 0) {
    FUN_004d6c90();
  }
  return;
}

