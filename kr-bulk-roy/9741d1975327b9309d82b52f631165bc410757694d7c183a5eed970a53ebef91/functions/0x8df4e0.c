
undefined4 FUN_008df4e0(int *param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 *puVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  int iVar8;
  
  uVar7 = param_2;
  piVar3 = param_1;
  iVar4 = *param_1;
  if ((*(byte *)(iVar4 + 8) & 2) != 0) {
    iVar4 = (**(code **)(*(int *)(iVar4 + 0x214) + 0x68))(iVar4,param_2,&param_1);
    if (iVar4 == 0) {
      uVar7 = FUN_008df400(piVar3,param_1);
      return uVar7;
    }
    piVar3[0xb] = -1;
  }
  FUN_008b8800(*piVar3,uVar7);
  iVar4 = FUN_008df080();
  if (iVar4 != 0) {
    iVar6 = *(int *)(*piVar3 + 0x290);
    iVar1 = *(int *)(iVar6 + 0x570);
    puVar2 = (undefined4 *)piVar3[10];
    (**(code **)(iVar4 + 4))(*puVar2,piVar3[4],piVar3[5],0,0);
    iVar8 = *(int *)(iVar6 + 0x768);
    if (iVar8 != 0) {
      param_1 = (int *)(iVar6 + 0x768 + iVar8 * 4);
      do {
        iVar6 = *(int *)(*param_1 + 0x44);
        if (iVar1 == iVar6) {
          iVar5 = piVar3[4];
          iVar6 = piVar3[5];
        }
        else {
          iVar5 = FUN_008b7dc0(piVar3[4],iVar1,iVar6);
          iVar6 = FUN_008b7dc0(piVar3[5],iVar1,iVar6);
        }
        (**(code **)(iVar4 + 4))(puVar2[iVar8],iVar5,iVar6,0,0);
        param_1 = param_1 + -1;
        iVar8 = iVar8 + -1;
      } while (iVar8 != 0);
    }
  }
  return 0;
}

