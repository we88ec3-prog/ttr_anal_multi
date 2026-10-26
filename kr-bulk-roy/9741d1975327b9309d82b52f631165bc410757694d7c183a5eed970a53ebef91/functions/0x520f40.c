
undefined4 FUN_00520f40(void)

{
  undefined4 in_EAX;
  int in_ECX;
  
                    /* WARNING (jumptable): Sanity check requires truncation of jumptable */
                    /* WARNING: Could not find normalized switch variable to match jumptable */
  switch((&DAT_00520fe8)[in_ECX]) {
  case 0:
    return 1;
  case 1:
    return 2;
  case 2:
    return 3;
  case 3:
    return 5;
  case 4:
    return 6;
  case 5:
    return 7;
  case 6:
    return 8;
  case 7:
    return 4;
  case 8:
    return 9;
  case 9:
    return 10;
  case 10:
    return 0xb;
  case 0xb:
    return 0xc;
  case 0xc:
    return 0xd;
  case 0xd:
    return 0xe;
  case 0xe:
    in_EAX = 0xf;
  }
  return in_EAX;
}

