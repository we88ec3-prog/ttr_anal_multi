
void FUN_00627240(int param_1)

{
  char cVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  int *in_EAX;
  int iVar5;
  int *piVar6;
  int local_10;
  int *local_c;
  int *local_8;
  
  if (in_EAX == (int *)0x0) {
LAB_00627279:
    in_EAX = (int *)0x0;
  }
  else {
    iVar5 = (**(code **)(*in_EAX + 4))();
    if (iVar5 != 0x105bd) {
      MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
      goto LAB_00627279;
    }
  }
  if (in_EAX[5] != 0x6a7) {
    return;
  }
  local_8 = (int *)in_EAX[6];
  if (local_8 != (int *)0x0) {
    iVar5 = (**(code **)(*local_8 + 4))();
    if (iVar5 == 0x105b9) goto LAB_006272b5;
    MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
  }
  local_8 = (int *)0x0;
LAB_006272b5:
  local_c = (int *)(param_1 + 0x10c);
  local_10 = 3;
  do {
    piVar2 = *(int **)(*local_c + 0x104);
    piVar6 = (int *)*piVar2;
    iVar5 = local_8[5];
    if (piVar6 != piVar2) {
      do {
        FUN_004738a0(piVar6 + (iVar5 + 1) * 4);
        if (*(char *)((int)piVar6 + 0x89) == '\0') {
          piVar3 = (int *)piVar6[2];
          if (*(char *)((int)piVar3 + 0x89) == '\0') {
            cVar1 = *(char *)(*piVar3 + 0x89);
            piVar6 = piVar3;
            piVar3 = (int *)*piVar3;
            while (cVar1 == '\0') {
              cVar1 = *(char *)(*piVar3 + 0x89);
              piVar6 = piVar3;
              piVar3 = (int *)*piVar3;
            }
          }
          else {
            cVar1 = *(char *)(piVar6[1] + 0x89);
            piVar4 = (int *)piVar6[1];
            piVar3 = piVar6;
            while ((piVar6 = piVar4, cVar1 == '\0' && (piVar3 == (int *)piVar6[2]))) {
              cVar1 = *(char *)(piVar6[1] + 0x89);
              piVar4 = (int *)piVar6[1];
              piVar3 = piVar6;
            }
          }
        }
      } while (piVar6 != piVar2);
    }
    FUN_0062b1d0();
    local_c = local_c + 1;
    local_10 = local_10 + -1;
  } while (local_10 != 0);
  FUN_0062cd40(*(undefined4 *)(param_1 + 0x118));
  FUN_0062d0b0(*(undefined4 *)(param_1 + 0x118));
  return;
}

