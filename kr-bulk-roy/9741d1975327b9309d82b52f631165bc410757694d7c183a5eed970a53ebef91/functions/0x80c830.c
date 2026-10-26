
void FUN_0080c830(int param_1)

{
  int iVar1;
  DWORD DVar2;
  
  iVar1 = *(int *)(param_1 + 0x14);
  while (iVar1 == 0) {
    DVar2 = WaitForSingleObject(*(HANDLE *)(param_1 + 4),500);
    if ((DVar2 == 0) && (*(int *)(param_1 + 0x10) != 0)) {
      InterlockedExchange((LONG *)(param_1 + 8),1);
      (**(code **)**(undefined4 **)(param_1 + 0x18))();
      InterlockedExchange((LONG *)(param_1 + 0x10),0);
      InterlockedExchange((LONG *)(param_1 + 8),0);
    }
    iVar1 = *(int *)(param_1 + 0x14);
  }
  if (*(int *)(param_1 + 0x10) != 0) {
                    /* WARNING: Could not recover jumptable at 0x0080c892. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)**(undefined4 **)(param_1 + 0x18))();
    return;
  }
  return;
}

