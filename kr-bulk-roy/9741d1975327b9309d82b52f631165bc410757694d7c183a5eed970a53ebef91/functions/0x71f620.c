
void FUN_0071f620(void)

{
  undefined4 *puVar1;
  int in_EAX;
  undefined4 in_EDX;
  undefined **local_18 [3];
  undefined4 local_c;
  undefined4 local_8;
  
  **(undefined4 **)(in_EAX + 0x20) = in_EDX;
  *(int *)(*(int *)(in_EAX + 0x20) + 4) = *(int *)(in_EAX + 8) - *(int *)(in_EAX + 0x18);
  puVar1 = *(undefined4 **)(in_EAX + 0x20);
  FUN_00891010();
  local_18[0] = pugi::xpath_exception::vftable;
  local_c = *puVar1;
  local_8 = puVar1[1];
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_18,&DAT_00c858e4);
}

