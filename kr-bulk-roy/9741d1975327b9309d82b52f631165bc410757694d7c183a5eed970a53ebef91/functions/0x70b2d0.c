
void FUN_0070b2d0(int param_1,char *param_2)

{
  char cVar1;
  int iVar2;
  char *in_EAX;
  char *pcVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 local_18 [2];
  undefined4 local_10;
  
  pcVar3 = _getenv(in_EAX);
  if (pcVar3 == (char *)0x0) {
    FUN_006f5510();
  }
  else {
    FUN_006f6740(&DAT_00c43ba8,&DAT_00c43ba4);
    FUN_006f6740(&DAT_00c411d4);
    puVar5 = *(undefined4 **)(param_1 + 8);
    puVar4 = puVar5 + -4;
    if (puVar4 < puVar5) {
      puVar5 = puVar5 + -8;
      do {
        *puVar5 = *puVar4;
        puVar5[1] = puVar4[1];
        puVar5[2] = puVar5[6];
        puVar4 = puVar4 + 4;
        puVar5 = puVar5 + 4;
      } while (puVar4 < *(undefined4 **)(param_1 + 8));
    }
    *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + -0x10;
  }
  FUN_00709df0();
  iVar2 = *(int *)(param_1 + 8);
  pcVar3 = param_2;
  do {
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  local_18[0] = FUN_006fec70(param_1,param_2,(int)pcVar3 - (int)(param_2 + 1));
  local_10 = 4;
  FUN_006fb9a0(param_1,iVar2 + -0x20,local_18,*(int *)(param_1 + 8) + -0x10);
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + -0x10;
  return;
}

