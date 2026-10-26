
undefined1 FUN_0074a120(int *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  char cVar4;
  int iVar5;
  int in_ECX;
  int *in_stack_00000018;
  undefined1 local_5;
  
  if (*(int *)(in_ECX + 0x24) == 0) {
    return 0;
  }
  puVar1 = (undefined4 *)*param_1;
  puVar2 = (undefined4 *)*puVar1;
  local_5 = 0;
  do {
    if (puVar2 == puVar1) {
      return local_5;
    }
    cVar4 = FUN_00755c50();
    if (cVar4 != '\0') {
      iVar3 = *in_stack_00000018;
      iVar5 = FUN_0074d550(iVar3,*(undefined4 *)(iVar3 + 4));
      if (in_stack_00000018[1] == 0xffffffe) {
                    /* WARNING: Subroutine does not return */
        FUN_0087db30("list<T> too long");
      }
      in_stack_00000018[1] = in_stack_00000018[1] + 1;
      *(int *)(iVar3 + 4) = iVar5;
      **(int **)(iVar5 + 4) = iVar5;
      local_5 = 1;
    }
    puVar2 = (undefined4 *)*puVar2;
  } while( true );
}

