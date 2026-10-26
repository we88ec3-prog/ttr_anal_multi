
int FUN_00718360(byte *param_1,int param_2)

{
  byte bVar1;
  byte *pbVar2;
  byte *pbVar3;
  int in_ECX;
  int iVar4;
  byte *pbVar5;
  
  if (*(int *)(in_ECX + 4) == 0) {
    FID_conflict__wprintf("File is not opened!\n");
    return 0;
  }
  if (param_2 != 0) {
    pbVar2 = param_1;
    pbVar5 = (byte *)0x0;
    if (*(char *)(in_ECX + 0x208) != '\0') {
      pbVar2 = (byte *)FUN_0087dc3d(param_2);
      pbVar3 = param_1;
      iVar4 = param_2;
      do {
        bVar1 = *pbVar3;
        pbVar3 = pbVar3 + 1;
        iVar4 = iVar4 + -1;
        pbVar3[(int)(pbVar2 + (-1 - (int)param_1))] = bVar1 ^ *(byte *)(in_ECX + 0x208);
        pbVar5 = pbVar2;
      } while (iVar4 != 0);
    }
    if (*(int **)(in_ECX + 4) == (int *)0x0) {
      iVar4 = 0;
    }
    else {
      iVar4 = (**(code **)(**(int **)(in_ECX + 4) + 0x14))(pbVar2,1,param_2);
    }
    if ((iVar4 != param_2) && (*(int **)(in_ECX + 4) != (int *)0x0)) {
      (**(code **)(**(int **)(in_ECX + 4) + 0x1c))();
    }
    if (*(char *)(in_ECX + 0x208) != '\0') {
      FUN_00891d3d(pbVar5);
    }
    return param_2;
  }
  return 0;
}

