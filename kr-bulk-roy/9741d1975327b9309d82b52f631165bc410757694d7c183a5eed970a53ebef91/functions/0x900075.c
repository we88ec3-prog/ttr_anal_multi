
/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */

int FUN_00900075(int *param_1,int param_2,_s_RTTICompleteObjectLocator *param_3,int param_4,
                int param_5)

{
  uint uVar1;
  int iVar2;
  int *piVar3;
  _s_RTTICompleteObjectLocator *p_Var4;
  int iVar5;
  _s_RTTIBaseClassDescriptor *p_Var6;
  TypeDescriptor *pTVar7;
  uint uVar8;
  PMD *in_stack_ffffffb8;
  bad_cast local_38 [12];
  uint local_2c;
  uint local_28;
  undefined4 local_24;
  void *local_20;
  undefined4 uStack_c;
  undefined4 local_8;
  
  uStack_c = 0x900081;
  if (param_1 == (int *)0x0) {
    return 0;
  }
  local_8 = 0;
  local_20 = (void *)FUN_008ffddd();
  pTVar7 = (TypeDescriptor *)((int)param_1 + (-(int)local_20 - param_2));
  uVar1 = *(uint *)(*(int *)(*(int *)(*param_1 + -4) + 0x10) + 4);
  if ((uVar1 & 1) == 0) {
    iVar5 = *(int *)(*(int *)(*param_1 + -4) + 0x10);
    iVar2 = *(int *)(iVar5 + 0xc);
    uVar1 = *(uint *)(iVar5 + 8);
    for (uVar8 = 0; local_28 = uVar8, uVar8 < uVar1; uVar8 = uVar8 + 1) {
      p_Var6 = *(_s_RTTIBaseClassDescriptor **)(iVar2 + uVar8 * 4);
      if ((*(int *)p_Var6 == param_4) ||
         (iVar5 = _strcmp((char *)(*(int *)p_Var6 + 8),(char *)(param_4 + 8)), iVar5 == 0))
      goto LAB_009000ed;
    }
    p_Var6 = (_s_RTTIBaseClassDescriptor *)0x0;
  }
  else if ((uVar1 & 2) == 0) {
    p_Var6 = FindMITargetTypeInstance
                       (local_20,param_3,pTVar7,param_4,(TypeDescriptor *)in_stack_ffffffb8);
  }
  else {
    p_Var6 = FindVITargetTypeInstance
                       (local_20,param_3,pTVar7,param_4,(TypeDescriptor *)in_stack_ffffffb8);
  }
  goto LAB_0090013f;
  while ((p_Var4 = (_s_RTTICompleteObjectLocator *)*piVar3, p_Var4 != param_3 &&
         (iVar5 = _strcmp((char *)(p_Var4 + 8),(char *)(param_3 + 8)), iVar5 != 0))) {
LAB_009000ed:
    uVar8 = uVar8 + 1;
    local_2c = uVar8;
    if ((uVar1 <= uVar8) ||
       (piVar3 = *(int **)(iVar2 + uVar8 * 4), (*(byte *)(piVar3 + 5) & 4) != 0)) goto LAB_00900161;
  }
LAB_0090013f:
  if (p_Var6 == (_s_RTTIBaseClassDescriptor *)0x0) {
LAB_00900161:
    iVar5 = 0;
    local_24 = 0;
    if (param_5 != 0) {
      std::bad_cast::bad_cast(local_38,"Bad dynamic_cast!");
                    /* WARNING: Subroutine does not return */
      __CxxThrowException_8(local_38,&DAT_00c85874);
    }
  }
  else {
    iVar5 = PMDtoOffset(local_20,in_stack_ffffffb8);
    iVar5 = iVar5 + (int)local_20;
  }
  return iVar5;
}

