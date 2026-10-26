
void FUN_006f4f40(undefined4 param_1,int param_2)

{
  int *piVar1;
  int *in_EAX;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  int local_10;
  int local_c;
  
  FUN_006f5510(param_1);
  iVar4 = *in_EAX;
  puVar2 = (undefined4 *)FUN_006f9c50();
  iVar4 = *(int *)(iVar4 + 8);
  *(undefined4 *)(iVar4 + -0x10) = *puVar2;
  *(undefined4 *)(iVar4 + -0xc) = puVar2[1];
  *(undefined4 *)(iVar4 + -8) = puVar2[2];
  iVar4 = *in_EAX;
  if ((*(undefined **)(iVar4 + 8) == &DAT_00c0bfd8) ||
     (*(int *)(*(undefined **)(iVar4 + 8) + -8) != 6)) {
    *(int *)(iVar4 + 8) = *(int *)(iVar4 + 8) + -0x10;
    iVar4 = *in_EAX;
    piVar1 = *(int **)(iVar4 + 8);
    iVar3 = piVar1[-2];
    if ((iVar3 == 5) || (iVar3 == 7)) {
      iVar3 = *(int *)(piVar1[-4] + 8);
    }
    else {
      iVar3 = *(int *)(*(int *)(iVar4 + 0x10) + 0x98 + iVar3 * 4);
    }
    if (iVar3 != 0) {
      *piVar1 = iVar3;
      piVar1[2] = 5;
      *(int *)(iVar4 + 8) = *(int *)(iVar4 + 8) + 0x10;
      iVar4 = FUN_006f6470();
      if (iVar4 != 0) {
        iVar4 = *in_EAX;
        puVar2 = *(undefined4 **)(iVar4 + 8);
        *puVar2 = puVar2[-8];
        puVar2[1] = puVar2[-7];
        puVar2[2] = puVar2[-6];
        piVar1 = (int *)(iVar4 + 8);
        *piVar1 = *piVar1 + 0x10;
        goto LAB_006f4fb8;
      }
    }
    FID_conflict__wprintf("Error : \'%s\' is not a metamethod\n",param_1);
  }
  else {
    puVar2 = *(undefined4 **)(iVar4 + 8);
    *puVar2 = puVar2[-8];
    puVar2[1] = puVar2[-7];
    puVar2[2] = puVar2[-6];
    *(int *)(iVar4 + 8) = *(int *)(iVar4 + 8) + 0x10;
LAB_006f4fb8:
    iVar3 = FUN_006f4cd0(in_EAX,&stack0x00000010);
    iVar4 = *in_EAX;
    local_10 = *(int *)(iVar4 + 8) + (iVar3 + 2) * -0x10;
    local_c = param_2;
    iVar3 = FUN_006fe770(FUN_006f5a50,&local_10,local_10 - *(int *)(iVar4 + 0x20));
    if (param_2 == -1) {
      if (*(uint *)(*(int *)(iVar4 + 0x14) + 8) <= *(uint *)(iVar4 + 8)) {
        *(uint *)(*(int *)(iVar4 + 0x14) + 8) = *(uint *)(iVar4 + 8);
      }
    }
    if (iVar3 != 0) {
      iVar4 = *in_EAX;
      iVar3 = *(int *)(iVar4 + 8);
      if (*(int *)(iVar3 + -8) != 4) {
        iVar3 = FUN_006fb5d0();
        if (iVar3 == 0) {
          FID_conflict__wprintf("Error running function : %s\n",0);
          return;
        }
        if (*(uint *)(*(int *)(iVar4 + 0x10) + 0x40) <= *(uint *)(*(int *)(iVar4 + 0x10) + 0x44)) {
          FUN_006fb3a0();
        }
        iVar3 = *(int *)(iVar4 + 8);
      }
      FID_conflict__wprintf("Error running function : %s\n",*(int *)(iVar3 + -0x10) + 0x10);
      return;
    }
  }
  return;
}

