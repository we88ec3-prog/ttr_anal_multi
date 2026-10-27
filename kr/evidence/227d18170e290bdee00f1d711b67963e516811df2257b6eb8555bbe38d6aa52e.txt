
void FUN_007dd1a0(int param_1,int param_2)

{
  if (0 < *(int *)(param_1 + 0x44)) {
    EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 100));
    FUN_007bb350();
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 100));
    return;
  }
  if (param_2 != 0) {
    FUN_007bd850();
    FUN_0089120c(param_2);
  }
  return;
}

