
void FUN_0055c520(char *param_1)

{
  int iVar1;
  undefined2 *unaff_ESI;
  undefined **local_10 [3];
  
  *unaff_ESI = param_1._0_2_;
  *(undefined4 *)(unaff_ESI + 6) = 0;
  iVar1 = FUN_00891268(0x10);
  if (iVar1 != 0) {
    *(int *)(unaff_ESI + 4) = iVar1;
    *(int *)iVar1 = iVar1;
    *(int *)(*(int *)(unaff_ESI + 4) + 4) = *(int *)(unaff_ESI + 4);
    *(int *)(*(int *)(unaff_ESI + 4) + 8) = *(int *)(unaff_ESI + 4);
    *(undefined1 *)(*(int *)(unaff_ESI + 4) + 0xe) = 1;
    *(undefined1 *)(*(int *)(unaff_ESI + 4) + 0xf) = 1;
    return;
  }
  param_1 = (char *)0x0;
  std::exception::exception((exception *)local_10,&param_1);
  local_10[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_10,&DAT_00c857a8);
}

