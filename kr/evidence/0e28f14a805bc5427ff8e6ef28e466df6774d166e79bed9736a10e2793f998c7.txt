
undefined4 FUN_004b7ec0(undefined4 param_1,undefined4 param_2,short param_3)

{
  undefined4 uVar1;
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x5eac) != 0) {
                    /* WARNING: Could not recover jumptable at 0x004b7ed8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (**(code **)(**(int **)(in_ECX + 0x5eac) + 4))();
    return uVar1;
  }
  FUN_006edb60("Received packet from invalid scene. Command #%d",(int)param_3);
  return 0;
}

