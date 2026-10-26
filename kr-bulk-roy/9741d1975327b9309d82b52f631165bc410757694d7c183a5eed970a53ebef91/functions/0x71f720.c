
void FUN_0071f720(undefined1 param_1,undefined1 param_2,int *param_3)

{
  int iVar1;
  undefined1 *puVar2;
  int unaff_ESI;
  
  if ((unaff_ESI == 1) && (*(char *)(*param_3 + 1) != '\x01')) {
                    /* WARNING: Subroutine does not return */
    FUN_0071f620();
  }
  puVar2 = (undefined1 *)FUN_0071bdb0();
  if (puVar2 == (undefined1 *)0x0) {
                    /* WARNING: Subroutine does not return */
    FUN_0071f670();
  }
  if (unaff_ESI != 0) {
    param_1 = param_2;
  }
  *puVar2 = param_1;
  iVar1 = *param_3;
  *(undefined2 *)(puVar2 + 1) = 3;
  puVar2[3] = 0;
  *(int *)(puVar2 + 4) = iVar1;
  *(undefined4 *)(puVar2 + 8) = 0;
  *(undefined4 *)(puVar2 + 0xc) = 0;
  return;
}

