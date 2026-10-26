
void FUN_00428210(undefined1 param_1)

{
  int iVar1;
  int iVar2;
  int in_EAX;
  int *piVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int local_c;
  
  *(undefined1 *)(in_EAX + 0x134) = param_1;
  piVar3 = (int *)(in_EAX + 0x124);
  local_c = 3;
  do {
    iVar1 = *piVar3;
    iVar6 = *(int *)(*(int *)(iVar1 + 0xec) + 0xcc);
    if (iVar6 == 0) {
      piVar4 = (int *)0x0;
    }
    else {
      piVar4 = (int *)(iVar6 + 0xa8);
    }
    iVar6 = 0;
    iVar7 = piVar4[1] - *piVar4 >> 2;
    if (0 < iVar7) {
      do {
        iVar2 = *(int *)(*(int *)(iVar1 + 0xec) + 0xcc);
        if (iVar2 != 0) {
          for (piVar4 = *(int **)(iVar2 + 0xa8); piVar4 != *(int **)(iVar2 + 0xac);
              piVar4 = piVar4 + 1) {
            iVar5 = *piVar4;
            if (*(int *)(iVar5 + 0x20) == iVar6) goto LAB_00428290;
          }
        }
        iVar5 = 0;
LAB_00428290:
        iVar6 = iVar6 + 1;
        *(undefined1 *)(iVar5 + 0x2a4) = param_1;
      } while (iVar6 < iVar7);
    }
    (**(code **)(**(int **)(iVar1 + 0xec) + 200))();
    piVar3 = piVar3 + 1;
    local_c = local_c + -1;
    if (local_c == 0) {
      return;
    }
  } while( true );
}

