
undefined4 FUN_008df400(int *param_1,int *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  param_1[0xb] = (int)param_2;
  FUN_008b8760(*param_1,param_2);
  iVar3 = FUN_008df080();
  if (iVar3 != 0) {
    iVar5 = *(int *)(*param_1 + 0x290);
    iVar1 = *(int *)(iVar5 + 0x570);
    puVar2 = (undefined4 *)param_1[10];
    (**(code **)(iVar3 + 4))(*puVar2,param_1[4],param_1[5],0,0);
    iVar6 = *(int *)(iVar5 + 0x768);
    if (iVar6 != 0) {
      param_2 = (int *)(iVar5 + 0x768 + iVar6 * 4);
      do {
        iVar5 = *(int *)(*param_2 + 0x44);
        if (iVar1 == iVar5) {
          iVar4 = param_1[4];
          iVar5 = param_1[5];
        }
        else {
          iVar4 = FUN_008b7dc0(param_1[4],iVar1,iVar5);
          iVar5 = FUN_008b7dc0(param_1[5],iVar1,iVar5);
        }
        (**(code **)(iVar3 + 4))(puVar2[iVar6],iVar4,iVar5,0,0);
        param_2 = param_2 + -1;
        iVar6 = iVar6 + -1;
      } while (iVar6 != 0);
    }
    return 0;
  }
  return 0;
}

