
void Catch_All_004ca507(void)

{
  int unaff_EBP;
  
  if (*(undefined4 **)(unaff_EBP + 0xc) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(unaff_EBP + 0xc))(1);
  }
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}

