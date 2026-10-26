
void FUN_00766dd0(void)

{
  int *in_EAX;
  
  in_EAX[0x50] = 0;
  FUN_00767ba0();
  FUN_00767ec0();
  FUN_00767b30();
  FUN_00767fa0();
                    /* WARNING: Could not recover jumptable at 0x00766e02. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*in_EAX + 0x1b0))();
  return;
}

