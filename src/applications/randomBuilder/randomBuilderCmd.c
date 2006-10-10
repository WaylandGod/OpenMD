/*
  File autogenerated by gengetopt version 2.16
  generated with the following command:
  gengetopt -F randomBuilderCmd --unamed-opts 

  The developers of gengetopt consider the fixed text that goes in all
  gengetopt output files to be in the public domain:
  we make no copyright claims on it.
*/

/* If we use autoconf.  */
#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "getopt.h"

#include "randomBuilderCmd.h"

static
void clear_given (struct gengetopt_args_info *args_info);
static
void clear_args (struct gengetopt_args_info *args_info);

static int
cmdline_parser_internal (int argc, char * const *argv, struct gengetopt_args_info *args_info, int override, int initialize, int check_required, const char *additional_error);

static int
cmdline_parser_required2 (struct gengetopt_args_info *args_info, const char *prog_name, const char *additional_error);

struct molFraction_list
{
  double molFraction_arg;
  char *molFraction_orig;
  struct molFraction_list * next;
};

static char *
gengetopt_strdup (const char *s);

static
void clear_given (struct gengetopt_args_info *args_info)
{
  args_info->help_given = 0 ;
  args_info->version_given = 0 ;
  args_info->output_given = 0 ;
  args_info->density_given = 0 ;
  args_info->nx_given = 0 ;
  args_info->ny_given = 0 ;
  args_info->nz_given = 0 ;
  args_info->molFraction_given = 0 ;
}

static
void clear_args (struct gengetopt_args_info *args_info)
{
  args_info->output_arg = NULL;
  args_info->output_orig = NULL;
  args_info->density_orig = NULL;
  args_info->nx_orig = NULL;
  args_info->ny_orig = NULL;
  args_info->nz_orig = NULL;
  args_info->molFraction_arg = NULL;
  args_info->molFraction_orig = NULL;
  
}

void
cmdline_parser_print_version (void)
{
  printf ("%s %s\n", CMDLINE_PARSER_PACKAGE, CMDLINE_PARSER_VERSION);
}

void
cmdline_parser_print_help (void)
{
  cmdline_parser_print_version ();
  printf("\nUsage: randomBuilder [OPTIONS]... [FILES]...\n\n");
  printf("%s\n","  -h, --help                Print help and exit");
  printf("%s\n","  -V, --version             Print version and exit");
  printf("%s\n","  -o, --output=STRING       Output file name");
  printf("%s\n","      --density=DOUBLE      density (g/cm^3)");
  printf("%s\n","      --nx=INT              number of unit cells in x");
  printf("%s\n","      --ny=INT              number of unit cells in y");
  printf("%s\n","      --nz=INT              number of unit cells in z");
  printf("%s\n","      --molFraction=DOUBLE  (Default) Builds a multi-component random mixed \n                              nanoparticle. Mole Fraction must be specified for \n                              each componet > 1 in MD file.");
  
}

void
cmdline_parser_init (struct gengetopt_args_info *args_info)
{
  clear_given (args_info);
  clear_args (args_info);

  args_info->inputs = NULL;
  args_info->inputs_num = 0;
}

static void
cmdline_parser_release (struct gengetopt_args_info *args_info)
{
  
  unsigned int i;
  if (args_info->output_arg)
    {
      free (args_info->output_arg); /* free previous argument */
      args_info->output_arg = 0;
    }
  if (args_info->output_orig)
    {
      free (args_info->output_orig); /* free previous argument */
      args_info->output_orig = 0;
    }
  if (args_info->density_orig)
    {
      free (args_info->density_orig); /* free previous argument */
      args_info->density_orig = 0;
    }
  if (args_info->nx_orig)
    {
      free (args_info->nx_orig); /* free previous argument */
      args_info->nx_orig = 0;
    }
  if (args_info->ny_orig)
    {
      free (args_info->ny_orig); /* free previous argument */
      args_info->ny_orig = 0;
    }
  if (args_info->nz_orig)
    {
      free (args_info->nz_orig); /* free previous argument */
      args_info->nz_orig = 0;
    }
  if (args_info->molFraction_arg)
    {
      for (i = 0; i < args_info->molFraction_given; ++i)
        {
          if (args_info->molFraction_orig [i])
            {
              free (args_info->molFraction_orig [i]); /* free previous argument */
              args_info->molFraction_orig [i] = 0;
            }
        }
      free (args_info->molFraction_arg); /* free previous argument */
      args_info->molFraction_arg = 0;
      free (args_info->molFraction_orig); /* free previous argument */
      args_info->molFraction_orig = 0;
    }
  
  for (i = 0; i < args_info->inputs_num; ++i)
    free (args_info->inputs [i]);
  
  if (args_info->inputs_num)
    free (args_info->inputs);
  
  clear_given (args_info);
}

int
cmdline_parser_file_save(const char *filename, struct gengetopt_args_info *args_info)
{
  FILE *outfile;
  int i = 0;

  outfile = fopen(filename, "w");

  if (!outfile)
    {
      fprintf (stderr, "%s: cannot open file for writing: %s\n", CMDLINE_PARSER_PACKAGE, filename);
      return EXIT_FAILURE;
    }

  if (args_info->help_given) {
    fprintf(outfile, "%s\n", "help");
  }
  if (args_info->version_given) {
    fprintf(outfile, "%s\n", "version");
  }
  if (args_info->output_given) {
    if (args_info->output_orig) {
      fprintf(outfile, "%s=\"%s\"\n", "output", args_info->output_orig);
    } else {
      fprintf(outfile, "%s\n", "output");
    }
  }
  if (args_info->density_given) {
    if (args_info->density_orig) {
      fprintf(outfile, "%s=\"%s\"\n", "density", args_info->density_orig);
    } else {
      fprintf(outfile, "%s\n", "density");
    }
  }
  if (args_info->nx_given) {
    if (args_info->nx_orig) {
      fprintf(outfile, "%s=\"%s\"\n", "nx", args_info->nx_orig);
    } else {
      fprintf(outfile, "%s\n", "nx");
    }
  }
  if (args_info->ny_given) {
    if (args_info->ny_orig) {
      fprintf(outfile, "%s=\"%s\"\n", "ny", args_info->ny_orig);
    } else {
      fprintf(outfile, "%s\n", "ny");
    }
  }
  if (args_info->nz_given) {
    if (args_info->nz_orig) {
      fprintf(outfile, "%s=\"%s\"\n", "nz", args_info->nz_orig);
    } else {
      fprintf(outfile, "%s\n", "nz");
    }
  }
  if (args_info->molFraction_orig)
    {
      for (i = 0; i < args_info->molFraction_given; ++i)
        {
          if (args_info->molFraction_orig [i])
            {
              fprintf(outfile, "%s=\"%s\"\n", "molFraction", args_info->molFraction_orig [i]);
            }
        }
    }
  
  fclose (outfile);

  i = EXIT_SUCCESS;
  return i;
}

void
cmdline_parser_free (struct gengetopt_args_info *args_info)
{
  cmdline_parser_release (args_info);
}


/* gengetopt_strdup() */
/* strdup.c replacement of strdup, which is not standard */
char *
gengetopt_strdup (const char *s)
{
  char *result = NULL;
  if (!s)
    return result;

  result = (char*)malloc(strlen(s) + 1);
  if (result == (char*)0)
    return (char*)0;
  strcpy(result, s);
  return result;
}

static char *
get_multiple_arg_token(const char *arg)
{
  char *tok, *ret;
  size_t len;

  if (!arg)
    return NULL;

  tok = strchr (arg, ',');

  if (tok)
    len = (size_t)(tok - arg + 1);
  else
    len = strlen (arg) + 1;

  ret = (char *) malloc (len);
  strncpy (ret, arg, len-1);
  ret[len-1] = '\0';

  return ret;
}

static char *
get_multiple_arg_token_next(const char *arg)
{
  char *tok;

  if (!arg)
    return NULL;

  tok = strchr (arg, ',');

  if (! tok || strlen(tok) == 1)
    return 0;

  return tok+1;
}

int
cmdline_parser (int argc, char * const *argv, struct gengetopt_args_info *args_info)
{
  return cmdline_parser2 (argc, argv, args_info, 0, 1, 1);
}

int
cmdline_parser2 (int argc, char * const *argv, struct gengetopt_args_info *args_info, int override, int initialize, int check_required)
{
  int result;

  result = cmdline_parser_internal (argc, argv, args_info, override, initialize, check_required, NULL);

  if (result == EXIT_FAILURE)
    {
      cmdline_parser_free (args_info);
      exit (EXIT_FAILURE);
    }
  
  return result;
}

int
cmdline_parser_required (struct gengetopt_args_info *args_info, const char *prog_name)
{
  int result = EXIT_SUCCESS;

  if (cmdline_parser_required2(args_info, prog_name, NULL) > 0)
    result = EXIT_FAILURE;

  if (result == EXIT_FAILURE)
    {
      cmdline_parser_free (args_info);
      exit (EXIT_FAILURE);
    }
  
  return result;
}

int
cmdline_parser_required2 (struct gengetopt_args_info *args_info, const char *prog_name, const char *additional_error)
{
  int error = 0;

  if (! args_info->output_given)
    {
      fprintf (stderr, "%s: '--output' ('-o') option required%s\n", prog_name, (additional_error ? additional_error : ""));
      error = 1;
    }
  if (! args_info->density_given)
    {
      fprintf (stderr, "%s: '--density' option required%s\n", prog_name, (additional_error ? additional_error : ""));
      error = 1;
    }
  if (! args_info->nx_given)
    {
      fprintf (stderr, "%s: '--nx' option required%s\n", prog_name, (additional_error ? additional_error : ""));
      error = 1;
    }
  if (! args_info->ny_given)
    {
      fprintf (stderr, "%s: '--ny' option required%s\n", prog_name, (additional_error ? additional_error : ""));
      error = 1;
    }
  if (! args_info->nz_given)
    {
      fprintf (stderr, "%s: '--nz' option required%s\n", prog_name, (additional_error ? additional_error : ""));
      error = 1;
    }

  return error;
}

int
cmdline_parser_internal (int argc, char * const *argv, struct gengetopt_args_info *args_info, int override, int initialize, int check_required, const char *additional_error)
{
  int c;	/* Character of the parsed option.  */
  char *multi_token, *multi_next; /* for multiple options */

  int i;        /* Counter */

  struct molFraction_list * molFraction_list = NULL,* molFraction_new = NULL;
  int error = 0;
  struct gengetopt_args_info local_args_info;

  if (initialize)
    cmdline_parser_init (args_info);

  cmdline_parser_init (&local_args_info);

  optarg = 0;
  optind = 0;
  opterr = 1;
  optopt = '?';

  while (1)
    {
      int option_index = 0;
      char *stop_char;

      static struct option long_options[] = {
        { "help",	0, NULL, 'h' },
        { "version",	0, NULL, 'V' },
        { "output",	1, NULL, 'o' },
        { "density",	1, NULL, 0 },
        { "nx",	1, NULL, 0 },
        { "ny",	1, NULL, 0 },
        { "nz",	1, NULL, 0 },
        { "molFraction",	1, NULL, 0 },
        { NULL,	0, NULL, 0 }
      };

      stop_char = 0;
      c = getopt_long (argc, argv, "hVo:", long_options, &option_index);

      if (c == -1) break;	/* Exit from `while (1)' loop.  */

      switch (c)
        {
        case 'h':	/* Print help and exit.  */
          cmdline_parser_print_help ();
          cmdline_parser_free (&local_args_info);
          exit (EXIT_SUCCESS);

        case 'V':	/* Print version and exit.  */
          cmdline_parser_print_version ();
          cmdline_parser_free (&local_args_info);
          exit (EXIT_SUCCESS);

        case 'o':	/* Output file name.  */
          if (local_args_info.output_given)
            {
              fprintf (stderr, "%s: `--output' (`-o') option given more than once%s\n", argv[0], (additional_error ? additional_error : ""));
              goto failure;
            }
          if (args_info->output_given && ! override)
            continue;
          local_args_info.output_given = 1;
          args_info->output_given = 1;
          if (args_info->output_arg)
            free (args_info->output_arg); /* free previous string */
          args_info->output_arg = gengetopt_strdup (optarg);
          if (args_info->output_orig)
            free (args_info->output_orig); /* free previous string */
          args_info->output_orig = gengetopt_strdup (optarg);
          break;


        case 0:	/* Long option with no short option */
          /* density (g/cm^3).  */
          if (strcmp (long_options[option_index].name, "density") == 0)
          {
            if (local_args_info.density_given)
              {
                fprintf (stderr, "%s: `--density' option given more than once%s\n", argv[0], (additional_error ? additional_error : ""));
                goto failure;
              }
            if (args_info->density_given && ! override)
              continue;
            local_args_info.density_given = 1;
            args_info->density_given = 1;
            args_info->density_arg = strtod (optarg, &stop_char);
            if (!(stop_char && *stop_char == '\0')) {
              fprintf(stderr, "%s: invalid numeric value: %s\n", argv[0], optarg);
              goto failure;
            }
            if (args_info->density_orig)
              free (args_info->density_orig); /* free previous string */
            args_info->density_orig = gengetopt_strdup (optarg);
          }
          /* number of unit cells in x.  */
          else if (strcmp (long_options[option_index].name, "nx") == 0)
          {
            if (local_args_info.nx_given)
              {
                fprintf (stderr, "%s: `--nx' option given more than once%s\n", argv[0], (additional_error ? additional_error : ""));
                goto failure;
              }
            if (args_info->nx_given && ! override)
              continue;
            local_args_info.nx_given = 1;
            args_info->nx_given = 1;
            args_info->nx_arg = strtol (optarg, &stop_char, 0);
            if (!(stop_char && *stop_char == '\0')) {
              fprintf(stderr, "%s: invalid numeric value: %s\n", argv[0], optarg);
              goto failure;
            }
            if (args_info->nx_orig)
              free (args_info->nx_orig); /* free previous string */
            args_info->nx_orig = gengetopt_strdup (optarg);
          }
          /* number of unit cells in y.  */
          else if (strcmp (long_options[option_index].name, "ny") == 0)
          {
            if (local_args_info.ny_given)
              {
                fprintf (stderr, "%s: `--ny' option given more than once%s\n", argv[0], (additional_error ? additional_error : ""));
                goto failure;
              }
            if (args_info->ny_given && ! override)
              continue;
            local_args_info.ny_given = 1;
            args_info->ny_given = 1;
            args_info->ny_arg = strtol (optarg, &stop_char, 0);
            if (!(stop_char && *stop_char == '\0')) {
              fprintf(stderr, "%s: invalid numeric value: %s\n", argv[0], optarg);
              goto failure;
            }
            if (args_info->ny_orig)
              free (args_info->ny_orig); /* free previous string */
            args_info->ny_orig = gengetopt_strdup (optarg);
          }
          /* number of unit cells in z.  */
          else if (strcmp (long_options[option_index].name, "nz") == 0)
          {
            if (local_args_info.nz_given)
              {
                fprintf (stderr, "%s: `--nz' option given more than once%s\n", argv[0], (additional_error ? additional_error : ""));
                goto failure;
              }
            if (args_info->nz_given && ! override)
              continue;
            local_args_info.nz_given = 1;
            args_info->nz_given = 1;
            args_info->nz_arg = strtol (optarg, &stop_char, 0);
            if (!(stop_char && *stop_char == '\0')) {
              fprintf(stderr, "%s: invalid numeric value: %s\n", argv[0], optarg);
              goto failure;
            }
            if (args_info->nz_orig)
              free (args_info->nz_orig); /* free previous string */
            args_info->nz_orig = gengetopt_strdup (optarg);
          }
          /* (Default) Builds a multi-component random mixed nanoparticle. Mole Fraction must be specified for each componet > 1 in MD file..  */
          else if (strcmp (long_options[option_index].name, "molFraction") == 0)
          {
            local_args_info.molFraction_given++;
          
            multi_token = get_multiple_arg_token(optarg);
            multi_next = get_multiple_arg_token_next (optarg);
          
            while (1)
              {
                molFraction_new = (struct molFraction_list *) malloc (sizeof (struct molFraction_list));
                molFraction_new->next = molFraction_list;
                molFraction_list = molFraction_new;
                molFraction_new->molFraction_arg = strtod (multi_token, &stop_char);
                if (!(stop_char && *stop_char == '\0')) {
                  fprintf(stderr, "%s: invalid numeric value: %s\n", argv[0], multi_token);
                  goto failure;
                }
                molFraction_new->molFraction_orig = multi_token;
          
                if (multi_next)
                  {
                    multi_token = get_multiple_arg_token(multi_next);
                    multi_next = get_multiple_arg_token_next (multi_next);
                    local_args_info.molFraction_given++;
                  }
                else
                  break;
              }
            break;
          }
          
          break;
        case '?':	/* Invalid option.  */
          /* `getopt_long' already printed an error message.  */
          goto failure;

        default:	/* bug: option not considered.  */
          fprintf (stderr, "%s: option unknown: %c%s\n", CMDLINE_PARSER_PACKAGE, c, (additional_error ? additional_error : ""));
          abort ();
        } /* switch */
    } /* while */


  if (local_args_info.molFraction_given && molFraction_list)
    {
      struct molFraction_list *tmp;
      args_info->molFraction_arg = (double *) realloc (args_info->molFraction_arg, (args_info->molFraction_given + local_args_info.molFraction_given) * sizeof (double));
      args_info->molFraction_orig = (char **) realloc (args_info->molFraction_orig, (args_info->molFraction_given + local_args_info.molFraction_given) * sizeof (char *));
      for (i = (local_args_info.molFraction_given - 1); i >= 0; --i)
        {
          tmp = molFraction_list;
          args_info->molFraction_arg [i + args_info->molFraction_given] = molFraction_list->molFraction_arg;
          args_info->molFraction_orig [i + args_info->molFraction_given] = molFraction_list->molFraction_orig;
          molFraction_list = molFraction_list->next;
          free (tmp);
        }
    }
  

  args_info->molFraction_given += local_args_info.molFraction_given;
  local_args_info.molFraction_given = 0;
  
  if (check_required)
    {
      error += cmdline_parser_required2 (args_info, argv[0], additional_error);
    }

  cmdline_parser_release (&local_args_info);

  if ( error )
    return (EXIT_FAILURE);

  if (optind < argc)
    {
      int i = 0 ;

      args_info->inputs_num = argc - optind ;
      args_info->inputs =
        (char **)(malloc ((args_info->inputs_num)*sizeof(char *))) ;
      while (optind < argc)
        args_info->inputs[ i++ ] = gengetopt_strdup (argv[optind++]) ;
    }

  return 0;

failure:
  if (molFraction_list)
    {
      struct molFraction_list *tmp;
      while (molFraction_list)
        {
          tmp = molFraction_list;
          free (molFraction_list->molFraction_orig);
          molFraction_list = molFraction_list->next;
          free (tmp);
        }
    }
  
  cmdline_parser_release (&local_args_info);
  return (EXIT_FAILURE);
}
