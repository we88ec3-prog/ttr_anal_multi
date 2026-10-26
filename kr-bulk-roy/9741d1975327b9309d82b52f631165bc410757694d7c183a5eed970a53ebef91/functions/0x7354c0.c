
void FUN_007354c0(int *param_1)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  int *unaff_ESI;
  int local_10;
  undefined4 *local_c;
  
  iVar1 = (**(code **)(*param_1 + 0x4c))(param_1,0,&local_10);
  if (-1 < iVar1) {
    iVar1 = unaff_ESI[1];
    if (iVar1 < unaff_ESI[3]) {
      iVar4 = unaff_ESI[2];
      do {
        iVar2 = *unaff_ESI;
        puVar3 = local_c;
        if (iVar2 < iVar4) {
          do {
            *puVar3 = 0;
            iVar4 = unaff_ESI[2];
            iVar2 = iVar2 + 1;
            puVar3 = puVar3 + 1;
          } while (iVar2 < iVar4);
        }
        local_c = (undefined4 *)((int)local_c + local_10);
        iVar1 = iVar1 + 1;
      } while (iVar1 < unaff_ESI[3]);
    }
    (**(code **)(*param_1 + 0x50))(param_1,0);
  }
  return;
}

