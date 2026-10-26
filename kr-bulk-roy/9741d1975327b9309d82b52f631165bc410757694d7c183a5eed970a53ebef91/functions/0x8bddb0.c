
int FUN_008bddb0(undefined4 param_1)

{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  int *unaff_ESI;
  int local_c;
  int local_8;
  
  local_c = unaff_ESI[1];
  piVar1 = (int *)unaff_ESI[3];
  iVar3 = local_c * 2;
  *unaff_ESI = iVar3 / 3;
  local_8 = 0;
  unaff_ESI[1] = iVar3;
  iVar3 = FUN_008bc7d0(param_1,4,0,iVar3,0,&local_8);
  unaff_ESI[3] = iVar3;
  if (local_8 == 0) {
    piVar5 = piVar1;
    if (0 < local_c) {
      do {
        puVar2 = (undefined4 *)*piVar5;
        if (puVar2 != (undefined4 *)0x0) {
          piVar4 = (int *)FUN_008bdd10(*puVar2);
          *piVar4 = (int)puVar2;
        }
        local_c = local_c + -1;
        piVar5 = piVar5 + 1;
      } while (local_c != 0);
    }
    FUN_008b9f80(param_1,piVar1);
  }
  return local_8;
}

