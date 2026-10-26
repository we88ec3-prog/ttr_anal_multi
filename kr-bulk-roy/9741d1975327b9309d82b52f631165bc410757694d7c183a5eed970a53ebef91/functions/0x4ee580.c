
void FUN_004ee580(int param_1,int param_2,undefined4 *param_3,code *param_4)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  char cVar5;
  int in_EAX;
  int iVar6;
  
  iVar1 = in_EAX;
  while( true ) {
    iVar6 = iVar1 * 2 + 2;
    if (param_2 <= iVar6) break;
    iVar2 = param_1 + iVar6 * 0xc;
    cVar5 = (*param_4)(iVar2,iVar2 + -0xc);
    if (cVar5 != '\0') {
      iVar6 = iVar1 * 2 + 1;
    }
    puVar3 = (undefined4 *)(param_1 + iVar6 * 0xc);
    puVar4 = (undefined4 *)(param_1 + iVar1 * 0xc);
    *puVar4 = *puVar3;
    puVar4[1] = puVar3[1];
    puVar4[2] = puVar3[2];
    iVar1 = iVar6;
  }
  if (iVar6 == param_2) {
    iVar6 = param_1 + -0xc + param_2 * 0xc;
    puVar3 = (undefined4 *)(param_1 + iVar1 * 0xc);
    *puVar3 = *(undefined4 *)(param_1 + -0xc + param_2 * 0xc);
    puVar3[1] = *(undefined4 *)(iVar6 + 4);
    puVar3[2] = *(undefined4 *)(iVar6 + 8);
    iVar1 = param_2 + -1;
  }
  while (in_EAX < iVar1) {
    iVar6 = (iVar1 + -1) / 2;
    puVar3 = (undefined4 *)(param_1 + iVar6 * 0xc);
    cVar5 = (*param_4)(puVar3,param_3);
    if (cVar5 == '\0') break;
    puVar4 = (undefined4 *)(param_1 + iVar1 * 0xc);
    *puVar4 = *puVar3;
    puVar4[1] = puVar3[1];
    puVar4[2] = puVar3[2];
    iVar1 = iVar6;
  }
  puVar3 = (undefined4 *)(param_1 + iVar1 * 0xc);
  *puVar3 = *param_3;
  puVar3[1] = param_3[1];
  puVar3[2] = param_3[2];
  return;
}

