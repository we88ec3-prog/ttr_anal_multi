
void FUN_007a7890(int param_1)

{
  LPCRITICAL_SECTION lpCriticalSection;
  int *piVar1;
  int *piVar2;
  
  if (*(int *)(param_1 + 0x108) != 0) {
    FUN_007be5f0();
  }
  piVar2 = (int *)**(int **)(param_1 + 0x10c);
  if (piVar2 != *(int **)(param_1 + 0x10c)) {
    do {
      piVar1 = (int *)piVar2[2];
      if (piVar1 != (int *)0x0) {
        *(int *)(*piVar1 + 0x60) = *(int *)(*piVar1 + 0x60) + -1;
        if ((piVar1[0x1d] == 0) || (piVar1[0x1e] == 0)) {
          if (0 < piVar1[0x1d]) {
            FUN_007be0f0(piVar1);
          }
        }
        else if (0 < *(int *)(*piVar1 + 0x44)) {
          lpCriticalSection = (LPCRITICAL_SECTION)(*piVar1 + 100);
          EnterCriticalSection(lpCriticalSection);
          FUN_007bb350();
          LeaveCriticalSection(lpCriticalSection);
          goto LAB_007a7927;
        }
        FUN_007bd850();
        FUN_0089120c(piVar1);
      }
LAB_007a7927:
      piVar1 = (int *)piVar2[3];
      if (piVar1 != (int *)0x0) {
        (**(code **)(*piVar1 + 0x10))();
        (**(code **)(*piVar1 + 8))();
      }
      piVar1 = (int *)*piVar2;
      if (piVar2 != *(int **)(param_1 + 0x10c)) {
        *(int **)piVar2[1] = piVar1;
        *(int *)(*piVar2 + 4) = piVar2[1];
        FUN_0089120c(piVar2);
        *(int *)(param_1 + 0x110) = *(int *)(param_1 + 0x110) + -1;
      }
      piVar2 = piVar1;
    } while (piVar1 != (int *)*(int *)(param_1 + 0x10c));
  }
  piVar2 = *(int **)(param_1 + 0x10c);
  piVar1 = (int *)*piVar2;
  *piVar2 = (int)piVar2;
  *(int *)(*(int *)(param_1 + 0x10c) + 4) = *(int *)(param_1 + 0x10c);
  *(undefined4 *)(param_1 + 0x110) = 0;
  if (piVar1 != *(int **)(param_1 + 0x10c)) {
    do {
      piVar2 = (int *)*piVar1;
      FUN_0089120c(piVar1);
      piVar1 = piVar2;
    } while (piVar2 != (int *)*(int *)(param_1 + 0x10c));
  }
  return;
}

