
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00686a60(void)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int in_ECX;
  int iVar4;
  
  iVar1 = *(int *)(*(int *)(in_ECX + 0x14c) + 0x24c);
  iVar4 = 0;
LAB_00686a80:
  do {
    iVar2 = *(int *)(*(int *)(in_ECX + 0x14c) + 0x24c);
    if ((iVar2 == 0) || (iVar2 = *(int *)(iVar2 + 0xcc), iVar2 == 0)) {
      iVar2 = 0;
    }
    else {
      iVar2 = *(int *)(iVar2 + 0xac) - *(int *)(iVar2 + 0xa8) >> 2;
    }
    if (iVar2 <= iVar4) {
      iVar1 = *(int *)(*(int *)(in_ECX + 0x158) + 0x24c);
      iVar4 = 0;
LAB_00686b10:
      do {
        iVar2 = *(int *)(*(int *)(in_ECX + 0x158) + 0x24c);
        if ((iVar2 == 0) || (iVar2 = *(int *)(iVar2 + 0xcc), iVar2 == 0)) {
          iVar2 = 0;
        }
        else {
          iVar2 = *(int *)(iVar2 + 0xac) - *(int *)(iVar2 + 0xa8) >> 2;
        }
        if (iVar2 <= iVar4) {
          return;
        }
        iVar2 = *(int *)(iVar1 + 0xcc);
        if (iVar2 != 0) {
          for (piVar3 = *(int **)(iVar2 + 0xa8); piVar3 != *(int **)(iVar2 + 0xac);
              piVar3 = piVar3 + 1) {
            if (((int *)*piVar3)[8] == iVar4) {
              (**(code **)(*(int *)*piVar3 + 0x54))();
              iVar4 = iVar4 + 1;
              goto LAB_00686b10;
            }
          }
        }
        (**(code **)(_DAT_00000000 + 0x54))();
        iVar4 = iVar4 + 1;
      } while( true );
    }
    iVar2 = *(int *)(iVar1 + 0xcc);
    if (iVar2 != 0) {
      for (piVar3 = *(int **)(iVar2 + 0xa8); piVar3 != *(int **)(iVar2 + 0xac); piVar3 = piVar3 + 1)
      {
        if (((int *)*piVar3)[8] == iVar4) {
          (**(code **)(*(int *)*piVar3 + 0x54))();
          iVar4 = iVar4 + 1;
          goto LAB_00686a80;
        }
      }
    }
    (**(code **)(_DAT_00000000 + 0x54))();
    iVar4 = iVar4 + 1;
  } while( true );
}

