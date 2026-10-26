
void FUN_00782420(int param_1,int param_2)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  undefined4 local_78;
  char local_74 [108];
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  puVar1 = *(undefined4 **)(*(int *)(param_1 + 0x74) + param_2 * 4);
  FUN_00725100(puVar1[2],0,0);
  if (DAT_00fe3200 == 0) {
    FUN_00783c70();
  }
  iVar3 = DAT_00fe3200;
  local_78 = *puVar1;
  piVar4 = (int *)FUN_0082ef00(&local_78);
  iVar2 = *piVar4;
  *(int *)(iVar3 + 0x10) = iVar2;
  if ((iVar2 == *(int *)(iVar3 + 4)) ||
     (piVar4 = (int *)(**(code **)(iVar2 + 0x10))(), piVar4 == (int *)0x0)) {
    _sprintf(local_74,"\nG-BLENDER :GB3 File Load Error : ClassID : [%x] Object is not registered\n"
             ,*puVar1);
    OutputDebugStringA(local_74);
  }
  else {
    (**(code **)(*piVar4 + 0x10))(param_1);
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

