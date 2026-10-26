
void FUN_006ee540(undefined4 *param_1)

{
  char *pcVar1;
  int iVar2;
  
  pcVar1 = (char *)*param_1;
  iVar2 = param_1[1];
  if (*pcVar1 == '\0') {
    do {
      WaitForSingleObject(*(HANDLE *)(*(int *)(pcVar1 + 4) + iVar2 * 4),0xffffffff);
      (**(code **)**(undefined4 **)(pcVar1 + 0x38))
                (*(undefined4 *)(iVar2 * 0xc + 8 + *(int *)(pcVar1 + 0x24)));
      SetEvent(*(HANDLE *)(*(int *)(pcVar1 + 0x14) + iVar2 * 4));
    } while (*pcVar1 == '\0');
  }
  __endthread();
  return;
}

