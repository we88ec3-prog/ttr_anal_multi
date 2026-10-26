
void FUN_006d9870(void)

{
  uint uVar1;
  int iVar2;
  int in_ECX;
  int *piVar3;
  int *piVar4;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00915f68;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  EnterCriticalSection((LPCRITICAL_SECTION)(in_ECX + 0xb4));
  local_8 = 0;
  if ((*(int *)(in_ECX + 0xa8) == 0) && (*(int *)(in_ECX + 0x2c) == 0)) {
    *(undefined4 *)(*(int *)(in_ECX + 0xac) + 0x10) = 0;
  }
  *(undefined4 *)(in_ECX + 0xa8) = 0;
  FUN_006d9970(uVar1);
  FUN_006d9970();
  FUN_006d9a10();
  FUN_006d9a10();
  piVar3 = (int *)**(int **)(in_ECX + 0x28);
  if (piVar3 != *(int **)(in_ECX + 0x28)) {
    do {
      iVar2 = FUN_006d9a10();
      if (iVar2 == 0) {
        piVar4 = (int *)*piVar3;
      }
      else {
        piVar4 = (int *)*piVar3;
        if (piVar3 != *(int **)(in_ECX + 0x28)) {
          *(int **)piVar3[1] = piVar4;
          *(int *)(*piVar3 + 4) = piVar3[1];
          if (0xf < (uint)piVar3[8]) {
            FUN_0089120c(piVar3[3]);
          }
          piVar3[8] = 0xf;
          piVar3[7] = 0;
          *(undefined1 *)(piVar3 + 3) = 0;
          FUN_0089120c(piVar3);
          *(int *)(in_ECX + 0x2c) = *(int *)(in_ECX + 0x2c) + -1;
        }
      }
      piVar3 = piVar4;
    } while (piVar4 != *(int **)(in_ECX + 0x28));
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(in_ECX + 0xb4));
  Sleep(0x21);
  ExceptionList = local_10;
  return;
}

