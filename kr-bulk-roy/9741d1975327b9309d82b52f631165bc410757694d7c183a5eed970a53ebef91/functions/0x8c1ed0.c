
void FUN_008c1ed0(void)

{
  int in_EAX;
  int iVar1;
  int iVar2;
  int *piVar3;
  int local_8;
  
  iVar2 = 0;
  if (*(int *)(in_EAX + 0x34) != 0) {
    *(undefined4 *)(in_EAX + 0x4d0) = 0;
    if (0 < *(int *)(in_EAX + 0x534)) {
      do {
        piVar3 = *(int **)(*(int *)(in_EAX + 0x530) + iVar2 * 4);
        iVar1 = 0;
        local_8 = 0;
        if (piVar3 != (int *)0x0) {
          do {
            if ((iVar1 < *piVar3) && (local_8 != 0)) {
              FUN_008c1da0(iVar1,iVar2,*piVar3 - iVar1);
            }
            local_8 = local_8 + piVar3[1];
            if ((local_8 * 0x200 != piVar3[2]) && (-1 < *piVar3)) {
              FUN_008c1da0(*piVar3,iVar2,1);
            }
            iVar1 = *piVar3;
            piVar3 = (int *)piVar3[3];
            iVar1 = iVar1 + 1;
          } while (piVar3 != (int *)0x0);
          if (local_8 != 0) {
            FUN_008c1da0(iVar1,iVar2,*(int *)(in_EAX + 0x18) - iVar1);
          }
        }
        iVar2 = iVar2 + 1;
      } while (iVar2 < *(int *)(in_EAX + 0x534));
    }
    if ((*(code **)(in_EAX + 0x4d4) != (code *)0x0) && (0 < *(int *)(in_EAX + 0x4d0))) {
      (**(code **)(in_EAX + 0x4d4))
                (*(undefined4 *)(in_EAX + 0x4dc),*(int *)(in_EAX + 0x4d0),in_EAX + 0x410,
                 *(undefined4 *)(in_EAX + 0x4d8));
    }
  }
  return;
}

