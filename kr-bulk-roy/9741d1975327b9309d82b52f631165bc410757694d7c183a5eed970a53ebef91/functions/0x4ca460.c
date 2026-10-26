
int * FUN_004ca460(undefined4 param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  undefined4 *puVar4;
  int *piVar5;
  undefined4 *puVar6;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00908920;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  puVar4 = (undefined4 *)FUN_00891268(0x10);
  puVar6 = (undefined4 *)0x0;
  if (puVar4 != (undefined4 *)0x0) {
    puVar4[1] = 1;
    puVar4[2] = 1;
    *puVar4 = std::tr1::_Ref_count<IS3D::CDoll>::vftable;
    puVar4[3] = param_2;
    puVar6 = puVar4;
  }
  piVar5 = (int *)FUN_007a31c0(param_2,puVar6);
  if (param_2 != 0) {
    if (puVar6 != (undefined4 *)0x0) {
      piVar5 = puVar6 + 2;
      LOCK();
      *piVar5 = *piVar5 + 1;
      UNLOCK();
    }
    piVar3 = *(int **)(param_2 + 0x14);
    if (piVar3 != (int *)0x0) {
      piVar1 = piVar3 + 2;
      LOCK();
      iVar2 = *piVar1;
      piVar5 = (int *)*piVar1;
      *piVar1 = iVar2 + -1;
      UNLOCK();
      if (iVar2 + -1 == 0) {
        piVar5 = (int *)(**(code **)(*piVar3 + 4))();
      }
    }
    *(undefined4 **)(param_2 + 0x14) = puVar6;
    *(int *)(param_2 + 0x10) = param_2;
  }
  ExceptionList = local_10;
  return piVar5;
}

