
void FUN_00520570(int param_1,int param_2,undefined4 *param_3,code *param_4)

{
  undefined4 *puVar1;
  char cVar2;
  int in_EAX;
  int iVar3;
  
  while (param_2 < in_EAX) {
    iVar3 = (in_EAX + -1) / 2;
    puVar1 = (undefined4 *)(param_1 + iVar3 * 0x14);
    cVar2 = (*param_4)(puVar1,param_3);
    if (cVar2 == '\0') break;
    *(undefined4 *)(param_1 + in_EAX * 0x14) = *puVar1;
    FUN_004fcdc0(puVar1 + 1);
    in_EAX = iVar3;
  }
  *(undefined4 *)(param_1 + in_EAX * 0x14) = *param_3;
  FUN_004fcdc0(param_3 + 1);
  return;
}

