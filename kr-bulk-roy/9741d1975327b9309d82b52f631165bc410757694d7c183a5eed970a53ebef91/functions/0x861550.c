
void FUN_00861550(int param_1,int param_2,undefined4 *param_3,code *param_4)

{
  char cVar1;
  int in_EAX;
  int iVar2;
  
  if (in_EAX <= param_2) {
    *(undefined4 *)(param_1 + in_EAX * 4) = *param_3;
    return;
  }
  do {
    iVar2 = (in_EAX + -1) / 2;
    cVar1 = (*param_4)(*(undefined4 *)(param_1 + iVar2 * 4),*param_3);
    if (cVar1 == '\0') {
      *(undefined4 *)(param_1 + in_EAX * 4) = *param_3;
      return;
    }
    *(undefined4 *)(param_1 + in_EAX * 4) = *(undefined4 *)(param_1 + iVar2 * 4);
    in_EAX = iVar2;
  } while (param_2 < iVar2);
  *(undefined4 *)(param_1 + iVar2 * 4) = *param_3;
  return;
}

